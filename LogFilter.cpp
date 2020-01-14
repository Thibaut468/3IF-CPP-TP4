/*************************************************************************
                           LogFilter  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
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
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
LogFilter::LogFilter ( const LogFilter & unLogFilter )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LogFilter>" << endl;
#endif
} //----- Fin de LogFilter (constructeur de copie)


LogFilter::LogFilter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogFilter>" << endl;
#endif
} //----- Fin de LogFilter


LogFilter::~LogFilter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LogFilter>" << endl;
#endif
} //----- Fin de ~LogFilter


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

