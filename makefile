CC=g++
CFLAGS=-g -Wall -Werror -ansi -pedantic -std=c++11
DFLAGS=

MAIN=analog
SRCS= main.cpp InputLogStream.cpp LogElement.cpp LogFilter.cpp LogTimeFilter.cpp LogExtensionFilter.cpp LogUnknownRefFilter.cpp Stats.cpp GraphGenerator.cpp
OBJS=$(SRCS:.c=.o)

$(MAIN): $(OBJS)
	@echo Compilation des objets et edition des liens
	@$(CC) -o $(MAIN) $(OBJS) $(DFLAGS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : dot
dot : 
	@echo Génération graphique dot en png
	dot -Tpng -o graph.png graph.dot

.PHONY : launch
launch : $(MAIN)
	./$(MAIN)

.PHONY : clean
clean:
	rm -f $(MAIN) *.o core
