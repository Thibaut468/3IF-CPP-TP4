/*************************************************************************
                       LogFilter  -  description
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par GRAVEY Thibaut & CHEN Gong
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <LogFilter> (fichier LogFilter.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LogFilter.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type LogFilter::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
LogFilter & LogFilter::operator = ( const LogFilter & unLogFilter )
// Algorithme :
// On renvoi simplement l'objet lui même car aucun attribut à copier
{
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

LogFilter::LogFilter ( const LogFilter & unLogFilter )
// Algorithme :
// /
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LogFilter>" << endl;
#endif
} //----- Fin de LogFilter (constructeur de copie)

LogFilter::LogFilter ( )
// Algorithme :
// /
{
#ifdef MAP
    cout << "Appel au constructeur de <LogFilter>" << endl;
#endif
} //----- Fin de LogFilter


LogFilter::~LogFilter ( )
// Algorithme :
// /
{
#ifdef MAP
    cout << "Appel au destructeur de <LogFilter>" << endl;
#endif
} //----- Fin de ~LogFilter


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
