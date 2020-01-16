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
#include "InputLogStream.h"
#include "LogElement.h"
#include "LogFilter.h"
#include "LogTimeFilter.h"
#include "LogExtensionFilter.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Fonctions publiques
// type main::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool ErrorHandler(int argc, char ** argv, bool & optionG, bool & optionE, bool & optionT)
{
    return true;
}

int main(int argc, char ** argv)
// Algorithme :
//
{
    //Mise en place des variables
    bool optionG(false);
    bool optionE(false);
    bool optionT(false);
    int timeFilter(4);

    LogTimeFilter * ltf = nullptr;
    LogExtensionFilter * lef = nullptr;
    int cpt(0);

    InputLogStream flux("../anonyme.log","http://intranet-if.insa-lyon.fr");

    //Vérification des erreurs d'entrées
    if(!ErrorHandler(argc, argv, optionG, optionE, optionT))
    {
         return EXIT_FAILURE;
    }

    //Vérification des erreurs du flux
    if(!flux.is_open())
    {
        cerr << "An error occured while opening the file." << endl;
        return EXIT_FAILURE;
    }

    cout << "Mise en place des filtres" << endl;

    //Mise en place des filtres
    vector<LogFilter*> filters;
    vector<string> extensionsFilter;
    extensionsFilter.emplace_back(".css");
    extensionsFilter.emplace_back(".js");
    extensionsFilter.emplace_back(".ico");
    extensionsFilter.emplace_back(".jpg");
    extensionsFilter.emplace_back(".png");
    extensionsFilter.emplace_back(".gif");
    extensionsFilter.emplace_back(".bmp");

    ltf = new LogTimeFilter(timeFilter,1);
    lef = new LogExtensionFilter(extensionsFilter);

    filters.emplace_back(ltf);
    filters.emplace_back(lef);

    //Récupération des données logs et traitement
    while(flux)
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
                cout << le << endl;
                cpt++;
            }
        }
    }

    //Affichage des résultats en fonction des options
    cout << "NbLignes acceptées : " << cpt << endl;

    //Destruction des espaces mémoires
    delete ltf;
    delete lef;

    return EXIT_SUCCESS;

} //----- Fin de main