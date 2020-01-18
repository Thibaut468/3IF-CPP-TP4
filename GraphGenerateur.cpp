/*************************************************************************
                           GraphGenerateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <GraphGenerateur> (fichier GraphGenerateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "GraphGenerateur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type GraphGenerateur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void GraphGenerateur::Generer(Map_Cibles_Pairs & unMapCibles){

    ofstream file;
    file.open("Cibles-Referer.dot");
    file<<"digraph {"<<endl;
    Map_Cibles_Pairs::iterator itC;
    Map_Referers_NbHit::iterator itR;
    int i = 0;
    for(itC = unMapCibles.begin(); itC != unMapCibles.end(); itC++){
        Nodes.push_back(itC->NameCible);
        file<<"node"<<i<<" [ label = \""<<itC->NameCible<<"\" ];"<<endl;
        i++;
        for(itR = unMapCibles.begin()->Pair.MapReferers.begin(); itR != unMapCibles.begin()->Pair.MapReferers.end(); itR++ ){
            Nodes.push_back(itC->NameCible);
            file<<"node"<<i<<" [ label = \""<<itR->NameRefere<<"\" ];"<<endl;
            i++;
        }
    }
    file<<endl;
    i = 0;
    int j = 1;
    for(itC = unMapCibles.begin(); itC != unMapCibles.end(); itC++){
        i =  j;
        j++;
        for(itR = unMapCibles.begin()->Pair.MapReferers.begin(); itR != unMapCibles.begin()->Pair.MapReferers.end(); itR++ ){
            file<< "node"<< i << " -> " <<"node"<< j << " [ label = \""<< itR->NbHit <<"\" ];"<<endl;
            j++;
        }
    }
    file<<"}"<<endl;
}


//------------------------------------------------- Surcharge d'opérateurs
//GraphGenerateur & GraphGenerateur::operator = ( const GraphGenerateur & unGraphGenerateur )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
GraphGenerateur::GraphGenerateur ( const GraphGenerateur & unGraphGenerateur )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GraphGenerateur>" << endl;
#endif
} //----- Fin de GraphGenerateur (constructeur de copie)


GraphGenerateur::GraphGenerateur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GraphGenerateur>" << endl;
#endif
} //----- Fin de GraphGenerateur

GraphGenerateur::~GraphGenerateur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GraphGenerateur>" << endl;
#endif
} //----- Fin de ~GraphGenerateur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
