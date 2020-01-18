/*************************************************************************
                           States  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <States> (fichier States.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "States.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type States::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void States::AjouterInfo (Informations info){
    MapCibles[info.URL].MapReferers[info.referer]++;
    MapCibles[info.URL].NbHitTotal++;
}

CiblesTop10 States::FindTop10()
// Algorithme : on cherche le NbHitTotal max dans le map MapCibles,
//  on l'enregistre dans un tableau, ensuite on remplace le NbHitTotal par 0,
// a la fin de l'execution, on remet les valeurs  de NbHitTotal
// but: eviter de verifier chaque fois si l'element existe deja dans myTop10
{
    CiblesTop10 myTop10(10);
    Map_Cibles_Pairs::iterator it;
    int NbHitTotalTop10  [10]= {0,0,0,0,0,0,0,0,0,0};

    for(int i = 0; i < 10; i++){
        for(it = MapCibles.begin(); it != MapCibles.end(); it++){
            if(it->Pair.NbHitTotal > NbHitTotalTop10[i]){
                myTop10[i] = it->NameCible;
                NbHitTotalTop10[i] = it->Pair.NbHitTotal;
            }
        }
        MapCibles[ myTop10[i] ].NbHitTotal = -1;
    }

    for(int j = 0; j < 10; j++){
       MapCibles[myTop10[j]].NbHitTotal = NbHitTotalTop10[j];
   }
    return myTop10;
}

void States::AffichageTop10(){
    CiblesTop10 desCiblesTop10 = FindTop10();
    int n = 0;

    cout<<"Top 10 cibles consultes par ordre decoissant"<<endl;
    for(int i = 0; i < 10; i++){
        n++;
        cout<<n<<"° : \" "<<desCiblesTop10[i]<<" \" "<<endl;
    }
}

//------------------------------------------------- Surcharge d'opérateurs
//States & States::operator = ( const States & unStates )
// Algorithme :
//
//{
//} //----- Fin de operator =

ostream & operator << (ostream & os, States & unState)
// Algorithme :
//
{
    Map_Cibles_Pairs::iterator IterCibles;
    Map_Referers_NbHit::iterator IterReferers;
    int n = 0;
    for(IterCibles =unState.GetMapCibles().begin(); IterCibles !=unState.GetMapCibles().end(); IterCibles++ ){
        os <<"*************************Cible et son nombre de hit total*************************" <<endl;
        os << "****** \"" << IterCibles->NameCible << "\"   \" Nombre de hit total: "  << IterCibles->Pair.NbHitTotal  << "\" ******"<<endl;
        os <<"*************************Referers correspondant - debut*************************" <<endl;
            for(IterReferers=IterCibles->Pair.MapReferers.begin(); IterReferers != IterCibles->Pair.MapReferers.end(); IterReferers++ ){
                n++;
               os<< "\"le "<<n<<"° referer: "<< IterReferers->NameRefere << "\" "<<"Nombre de hit correspondant: "<<  IterReferers->NbHit << "\""<<endl;
            }
        os <<"*************************Referers correspondant - fin*************************" <<endl;
        n = 0;
        os<<endl<<endl;
    }
    return os;
} //----- Fin de operator <<

Map_Cibles_Pairs & States::GetMapCibles(){
    return MapCibles;
}

//-------------------------------------------- Constructeurs - destructeur
States::States ( const States & unStates )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <States>" << endl;
#endif
} //----- Fin de States (constructeur de copie)


States::States ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <States>" << endl;
#endif
} //----- Fin de States


States::~States ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <States>" << endl;
#endif
} //----- Fin de ~States


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
