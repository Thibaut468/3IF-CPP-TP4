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
        "Syntax error : Invalid time.",
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
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Fonctions publiques
// type main::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//Prototype de la fonction définie sous la fonction main
void ErrorHandler(int argc, char ** argv, InputLogStream * flux, ArgStatus & status, bool & optionG, bool & optionE, bool & optionT, int & timeFilter);

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

    LogTimeFilter * ltf = nullptr;
    LogExtensionFilter * lef = nullptr;

    int cpt(0);

    InputLogStream * flux = nullptr;

    //Vérification des erreurs d'entrées et ouverture du flux
    ErrorHandler(argc, argv, flux, applicationStatus, optionG, optionE, optionT, timeFilter);

    if(applicationStatus!=ArgStatus::SUCCESS)
    {
        cerr << StatusMessage[applicationStatus] << endl;
        return EXIT_FAILURE;
    }

    //return EXIT_FAILURE;

    cout << "Mise en place des filtres" << endl;

    //Mise en place des filtres
    vector<LogFilter*> filters;

    if(optionG)
    {

    }

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

    //Récupération des données logs et traitement
    while(*flux)
    {
        bool valid(true);
        LogElement le;
        if (*flux >> le)
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
    delete flux;

    return EXIT_SUCCESS;

} //----- Fin de main

void ErrorHandler(int argc, char ** argv, InputLogStream * flux, ArgStatus & status, bool & optionG, bool & optionE, bool & optionT, int & timeFilter)
// Algorithme
//
{
    if(argc == 1) //Pas d'arguments
    {
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

    cout << command << endl;

    istringstream cmd_flux(command);
    string tampon;

    //Traitement du premier argument : le fichier log
    cmd_flux>>tampon;

    flux = new InputLogStream("../"+tampon,SERVER_URL);

    if(!(*flux).is_open())
    {
        status = ArgStatus::ERROR_INVALID_LOG_OPENING;
        return;
    }

    while(cmd_flux)
    {
        cmd_flux>>tampon;
        cout << "Partie analysé : " << tampon << endl;

        if(tampon=="-g")
        {
            if(optionG) //Doublon de parametre
            {
                status=ArgStatus::ERROR_SYNTAX_UNREPEATABLE_OPTION_G;
                return;
            }

            optionG=true;

            cmd_flux>>tampon;

            ifstream dotFile(tampon);
            if(dotFile)
            {
                status = ArgStatus::ERROR_SYNTAX_DOT_EXIST;
                return;
            }

            dotFile.close();

            if(tampon.substr(tampon.length()-4)!=".dot")
            {
                status = ArgStatus::ERROR_SYNTAX_DOT_EXT_OPTION_G;
                return;
            }

            ofstream dotFileOutput(tampon);
            if(!dotFileOutput)
            {
                status = ArgStatus::ERROR_SYNTAX_DOT_CANT_OPEN_OPTION_G;
                return;
            }

            dotFileOutput.close();

        }
        else if(tampon == "-e")
        {
            if(optionE) //Doublon de parametre
            {
                status=ArgStatus::ERROR_SYNTAX_UNREPEATABLE_OPTION_E;
                return;
            }

            optionE=true;
        }
        else if(tampon == "-t")
        {
            if(optionT) //Doublon de parametre
            {
                status=ArgStatus::ERROR_SYNTAX_UNREPEATABLE_OPTION_T;
                return;
            }

            optionT=true;

            cmd_flux.clear();
            cmd_flux>>timeFilter;

            if(!cmd_flux)
            {
                status=ArgStatus::ERROR_SYNTAX_NO_TIME_OPTION_T;
                return;
            }
        }
        else
        {
            status=ArgStatus::ERROR_SYNTAX;
            return;
        }
    }

} // ----- Fin de ErrorHandler
