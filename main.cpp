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
#include "States.h"
#include "GraphGenerateur.h"
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

    int cpt(0);

    States state;
    GraphGenerateur graphGenerateur;

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

    //Mise en place des filtres
    vector<LogFilter> filters;

    //Récupération des données logs et traitement
    while(flux)
    {
        bool valid(true);
        LogElement le;
        if (flux >> le)
        {

            state.AjouterInfo(le.GetInfos());
            cpt++;

        //    cout<<le<<endl<<endl;
            for(vector<LogFilter>::iterator it=filters.begin(); it!=filters.end(); ++it)
            {
                //Mettre a jour valid a false si besoin
            }

            if(valid)
            {
                //AJOUTER DANS LES STATS
            }
        }
    }

    //Affichage des résultats en fonction des options
    cout<<state<<endl;
    cout << "NbLignes traitées : " << cpt << endl;
    state.AffichageTop10();
    graphGenerateur.Generer(state.GetMapCibles());

    return EXIT_SUCCESS;

} //----- Fin de main
