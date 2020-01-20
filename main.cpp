/*************************************************************************
                   main  -  Point d'entrée de l'application
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par GRAVEY Thibaut & CHEN Gong
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <main> (fichier main.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <map>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "InputLogStream.h"
#include "LogElement.h"
#include "LogFilter.h"
#include "LogTimeFilter.h"
#include "LogExtensionFilter.h"
#include "Stats.h"
#include "GraphGenerator.h"

//------------------------------------------------------------- Types

enum ArgStatus {
    SUCCESS,
    ERROR_SYNTAX,
    ERROR_INVALID_TIME,
    ERROR_INVALID_LOG_OPENING,
    ERROR_SYNTAX_DOT_EXIST,
    ERROR_SYNTAX_UNREPEATABLE_OPTION_E,
    ERROR_SYNTAX_UNREPEATABLE_OPTION_G,
    ERROR_SYNTAX_UNREPEATABLE_OPTION_T,
    ERROR_SYNTAX_NO_TIME_OPTION_T,
    ERROR_SYNTAX_DOT_EXT_OPTION_G,
    ERROR_SYNTAX_DOT_CANT_OPEN_OPTION_G,
    ARGS_STATUS_SIZE
};

//------------------------------------------------------------- Constantes

static string  StatusMessage[ArgStatus::ARGS_STATUS_SIZE] = {
        "Analog launched without errors.",
        "Syntax error.",
        "Syntax error : Invalid time - Parameter must be an integer in [0,23]",
        "Syntax error : Invalid log file - Can't open it.",
        "Syntax error : Dot file already exist",
        "Syntax error : You can't repeat option -e in analog command",
        "Syntax error : You can't repeat option -g in analog command",
        "Syntax error : You can't repeat option -t in analog command",
        "Syntax error :  Option -t not followed by an int",
        "Syntax error :  Option -g not followed by a dot file",
        "Syntax error :  Option -g can't create a dot file with this name"
};

static string SERVER_URL = "http://intranet-if.insa-lyon.fr";

static int TIME_INTERVAL(1);

static int LOG_LIMIT = 10000000;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Fonctions publiques
// type main::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//Prototype de la fonction définie sous la fonction main
void ErrorHandler(int argc, char ** argv,string & logName, ArgStatus & status, bool & optionG, bool & optionE, bool & optionT, int & timeFilter, string & dotName);

int main(int argc, char ** argv)
// Algorithme :
//
{
    //Mise en place des variables
    ArgStatus applicationStatus = ArgStatus::SUCCESS;
    bool optionG(false);
    bool optionE(false);
    bool optionT(false);
    int timeFilter(0);
    string logName;
    string dotName;

    LogTimeFilter * ltf = nullptr;
    LogExtensionFilter * lef = nullptr;

    int cpt(0);

    GraphGenerator * graphGenerator = nullptr;
    Stats stats;

    //Vérification des erreurs d'entrées et ouverture du flux
    ErrorHandler(argc, argv, logName, applicationStatus, optionG, optionE, optionT, timeFilter,dotName);

    if(applicationStatus!=ArgStatus::SUCCESS)
    {
        cerr << StatusMessage[applicationStatus] << endl;
        return EXIT_FAILURE;
    }

    //Ouverture du flux (le fichier log)
    InputLogStream flux("../"+logName,SERVER_URL);

    if(!flux)
    {
        applicationStatus=ArgStatus::ERROR_INVALID_LOG_OPENING;
        cerr << StatusMessage[applicationStatus] << endl;
        return EXIT_FAILURE;
    }

    cout << "Mise en place des filtres" << endl;

    //Mise en place des filtres
    vector<LogFilter*> filters;

    if(optionT)
    {
        ltf = new LogTimeFilter(timeFilter,TIME_INTERVAL);

        filters.emplace_back(ltf);
    }

    if(optionE)
    {
        vector<string> extensionsFilter;

        extensionsFilter.emplace_back(".css");
        extensionsFilter.emplace_back(".js");
        extensionsFilter.emplace_back(".ico");
        extensionsFilter.emplace_back(".jpg");
        extensionsFilter.emplace_back(".png");
        extensionsFilter.emplace_back(".gif");
        extensionsFilter.emplace_back(".bmp");

        lef = new LogExtensionFilter(extensionsFilter);

        filters.emplace_back(lef);
    }

    cout << "Récupération données" << endl;
    //Récupération des données logs et traitement
    while(flux && cpt < LOG_LIMIT)
    {

        bool valid(true);
        LogElement le;
        if (flux >> le)
        {
            for(vector<LogFilter*>::iterator it=filters.begin(); it!=filters.end(); ++it)
            {
                valid = (**it).Authorize(le);

                if(!valid)
                {
                    break;
                }
            }

            if(valid)
            {
                //cout << le << endl;
                stats.AjouterInfo(le.GetInfos());
                cpt++;
            }
        }
    }

    //Affichage des résultats en fonction des options
    cout << "NbLignes acceptées : " << cpt << endl;

    cout << stats << endl << endl;


    //Affichage du top 10 dans tous les cas

    stats.AffichageTop10();

    // Instanciation d'un générateur de graphes si l'option -g est activée
    if(optionG)
    {
        graphGenerator = new GraphGenerator();
        graphGenerator->Generer(stats.GetMapCibles(),dotName);
    }

    //Destruction des espaces mémoires
    delete ltf;
    delete lef;
    delete graphGenerator;

    return EXIT_SUCCESS;

} //----- Fin de main

void ErrorHandler(int argc, char ** argv, string & logName, ArgStatus & status, bool & optionG, bool & optionE, bool & optionT, int & timeFilter, string & dotName)
// Algorithme
//
{
    bool logFind(false);

    if(argc == 1) //Pas d'arguments
    {
        cout << "191" << endl;
        status=ArgStatus::ERROR_SYNTAX;
        return;
    }

    //Récupération des arguments intéressants (on retire argv[0] = analog
    string command;
    for(unsigned int i = 1; i<argc; ++i)
    {
        if(!command.empty())
        {
            command += " ";
        }
        command += string(argv[i]);
    }

    cout << "command = "<< command << endl;

    istringstream cmd_flux(command);
    string tampon;

    while(cmd_flux>>tampon) {

        cout << "Partie analysé : " << tampon << endl;

        if(tampon.length()>4 && tampon.substr(tampon.length()-4)==".log")
        {
            logFind=true;

            InputLogStream flux("../"+tampon,SERVER_URL);

            if(!flux.is_open())
            {
                cout << "236 et tampon = " << tampon << endl;
                status = ArgStatus::ERROR_INVALID_LOG_OPENING;
                return;
            }

            flux.close();

            logName=tampon;

        }
        else if(tampon=="-g")
        {
            if(optionG) //Doublon de parametre
            {
                cout << "248 et tampon = " << tampon << endl;
                status=ArgStatus::ERROR_SYNTAX_UNREPEATABLE_OPTION_G;
                return;
            }

            optionG=true;

            if(cmd_flux.eof())
            {
                cout << "261 fin de fichier sans dotName " << endl;
                status = ArgStatus::ERROR_SYNTAX;
                return;
            }

            cmd_flux>>tampon;

            if(tampon.substr(tampon.length()-4)!=".dot")
            {
                cout << "259 et tampon = " << tampon << endl;
                status = ArgStatus::ERROR_SYNTAX_DOT_EXT_OPTION_G;
                return;
            }

            ifstream dotFile(tampon);
            if(dotFile)
            {
                cout << "249 et tampon = " << tampon << endl;
                status = ArgStatus::ERROR_SYNTAX_DOT_EXIST;
                return;
            }

            dotFile.close();


            ofstream dotFileOutput(tampon);
            if(!dotFileOutput)
            {
                cout << "278 et tampon = " << tampon << endl;
                status = ArgStatus::ERROR_SYNTAX_DOT_CANT_OPEN_OPTION_G;
                return;
            }

            dotFileOutput.close();

            dotName=tampon;

        }
        else if(tampon == "-e")
        {
            if(optionE) //Doublon de parametre
            {
                cout << "292 et tampon = " << tampon << endl;
                status=ArgStatus::ERROR_SYNTAX_UNREPEATABLE_OPTION_E;
                return;
            }

            optionE=true;
        }
        else if(tampon == "-t")
        {
            if(optionT) //Doublon de parametre
            {
                cout << "303 et tampon = " << tampon << endl;
                status=ArgStatus::ERROR_SYNTAX_UNREPEATABLE_OPTION_T;
                return;
            }

            optionT=true;

            if(cmd_flux.eof())
            {
                cout << "321 et fin de fichier , pas de parametre temps " << endl;
                status=ArgStatus::ERROR_SYNTAX;
                return;
            }

            cmd_flux.clear();
            cmd_flux>>timeFilter;

            if(!cmd_flux)
            {
                cout << "315 et tampon = " << tampon << endl;
                status=ArgStatus::ERROR_SYNTAX_NO_TIME_OPTION_T;
                return;
            }

            if((timeFilter<0) || (timeFilter > 23))
            {
                cout << "322 et tampon = " << tampon << endl;
                status=ArgStatus::ERROR_INVALID_TIME;
                return;
            }
        }
        else
        {
            cout << "329 et tampon = " << tampon << endl;
            status=ArgStatus::ERROR_SYNTAX;
            return;
        }
    }

    if(!logFind)
    {
        status=ArgStatus::ERROR_SYNTAX;
        return;
    }

} // ----- Fin de ErrorHandler
