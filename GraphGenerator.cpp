/*************************************************************************
                           GraphGenerateur  -  description
                             -------------------
    début                : 21/01/2020
    copyright            : (C) 2020 par GRAVEY Thibaut & CHEN Gong
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

void GraphGenerator::Generer(Map_Cibles_Pairs & unMapCibles, string & dotName)
// Algorithme : pour eviter de creer plusieur fois le meme noeud, on utilise un if-else et un tempon d'int pour
// retrouver le nom du noeud(soit un cible soit un referer).
// le int i, et int j ici sont pour nommer les noeuds
{
    ofstream file;
    file.open(dotName, ios::out | ios::trunc );
    file<<"digraph {"<<endl;
    Map_Cibles_Pairs::iterator itC;
    Map_Referers_NbHit::iterator itR;
    vector<string>::iterator itV;

    int i = 0;  // pour cibles
    int j = 0;  // pour referers
    int tmp = 0;

    for(itC = unMapCibles.begin(); itC != unMapCibles.end(); itC++){
        i = j;
        ++j;
        itV = find(nodes.begin(), nodes.end(), itC->NameCible);
        if( itV == nodes.end()){
            nodes.push_back(itC->NameCible);
            file<<"node"<<i<<" [ label = \""<<itC->NameCible<<"\" ];"<<endl;
        }else{
            tmp = i;
            i = distance(nodes.begin(),itV);
        }
        for(itR = itC->Pair.MapReferers.begin(); itR != itC->Pair.MapReferers.end(); itR++ ){
            if(itR->NameRefere == "-"){
                continue;
            }
            itV = find(nodes.begin(), nodes.end(), itR->NameRefere);
            if( itV == nodes.end() ){
                nodes.push_back(itR->NameRefere);
                file<<"node"<<j<<" [ label = \""<<itR->NameRefere<<"\" ];"<<endl;
                file<< "node"<< j << " -> " <<"node"<< i << " [ label = \""<< itR->NbHit <<"\" ];"<<endl;
                ++j;
            }else{
                tmp = j;
                j = distance(nodes.begin(),itV);
                file<< "node"<< j << " -> " <<"node"<< i << " [ label = \""<< itR->NbHit <<"\" ];"<<endl;
                j = tmp;
            }
        }
        file<<endl;
    }
    file<<"}"<<endl;

    cout << "File "+dotName+" generate with success." << endl;
}


//------------------------------------------------- Surcharge d'opérateurs
GraphGenerator & GraphGenerator::operator=(const GraphGenerator &unGraphGenerateur)
// Algorithme :
// Copie simple de chaque attribut dans le nouvel objet, en évitant le cas gg1=gg1
{
    if(this!=&unGraphGenerateur)
    {
        nodes.clear();
        for(vector<string>::const_iterator it=unGraphGenerateur.nodes.begin(); it!=unGraphGenerateur.nodes.end(); ++it)
        {
            nodes.emplace_back((*it));
        }
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
GraphGenerator::GraphGenerator (const GraphGenerator & unGraphGenerateur )
// Algorithme :
//
{

    for(vector<string>::const_iterator it=unGraphGenerateur.nodes.begin(); it!=unGraphGenerateur.nodes.end(); ++it)
    {
        nodes.emplace_back((*it));
    }

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
