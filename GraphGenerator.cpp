/*************************************************************************
                           GraphGenerateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <GraphGenerator> (fichier GraphGenerator.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "GraphGenerator.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type GraphGenerator::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void GraphGenerator::Generer(Map_Cibles_Pairs & unMapCibles, string & dotName){

    ofstream file;
    file.open(dotName);
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
//GraphGenerator & GraphGenerator::operator = ( const GraphGenerator & unGraphGenerateur )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
GraphGenerator::GraphGenerator (const GraphGenerator & unGraphGenerateur )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GraphGenerator>" << endl;
#endif
} //----- Fin de GraphGenerator (constructeur de copie)


GraphGenerator::GraphGenerator ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GraphGenerator>" << endl;
#endif
} //----- Fin de GraphGenerator

GraphGenerator::~GraphGenerator ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GraphGenerator>" << endl;
#endif
} //----- Fin de GraphGenerator

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
