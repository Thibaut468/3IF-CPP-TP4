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

//------------------------------------------------------ Include personnel
#include "main.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Fonctions publiques
// type main::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

int main(int argc, char ** argv)
// Algorithme :
//
{
    InputLogStream flux("/tmp/anonyme.log","http://intranet-if.insa-lyon.fr");

    int cpt(0);

    if(!flux.is_open())
    {
        cerr << "An error occured while opening the file." << endl;
        return -1;
    }

    while(flux)
    {
        LogElement le;
        flux>>le;
        cout << le << endl;
        cpt++;
    }

    cout << "NbLignes traitées : " << cpt << endl;



} //----- Fin de main