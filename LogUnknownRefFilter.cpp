/*************************************************************************
                       LogUnknownRefFilter  -  description
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par GRAVEY Thibaut & CHEN Gong
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <LogUnknownRefFilter> (fichier LogUnknownRefFilter.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <algorithm>

//------------------------------------------------------ Include personnel
#include "LogUnknownRefFilter.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type LogUnknownRefFilter::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool LogUnknownRefFilter::Authorize(LogElement &le) const
// Algorithme
//
{
    return (find(unknownName.begin(),unknownName.end(),le.GetInfos().referer)==unknownName.end());
} // ---- Fin de Authorize

void LogUnknownRefFilter::AddName(string name)
//Algorithme
//
{
    unknownName.push_back(name);
}
// ---- Fin de AddName

bool LogUnknownRefFilter::RemoveName(string name)
//Algorithme
//
{
    vector<string>::iterator pos = find(unknownName.begin(),unknownName.end(),name);
    if(pos!=unknownName.end())
    {
        unknownName.erase(pos);
        return true;
    }

    return false;
}
// ---- Fin de AddName

//------------------------------------------------- Surcharge d'opérateurs
LogUnknownRefFilter & LogUnknownRefFilter::operator = ( const LogUnknownRefFilter & unLogUnknownRefFilter )
// Algorithme :
//
{
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

LogUnknownRefFilter::LogUnknownRefFilter ( const LogUnknownRefFilter & unLogUnknownRefFilter )
// Algorithme :
//
{

    for(vector<string>::const_iterator it=unLogUnknownRefFilter.unknownName.begin(); it!=unLogUnknownRefFilter.unknownName.end(); ++it)
    {
        unknownName.emplace_back(*it);
    }

#ifdef MAP
    cout << "Appel au constructeur de copie de <LogUnknownRefFilter>" << endl;
#endif
} //----- Fin de LogUnknownRefFilter (constructeur de copie)

LogUnknownRefFilter::LogUnknownRefFilter (vector<string> & name) : LogFilter()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogUnknownRefFilter>" << endl;
#endif
} //----- Fin de LogUnknownRefFilter


LogUnknownRefFilter::~LogUnknownRefFilter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LogUnknownRefFilter>" << endl;
#endif
} //----- Fin de ~LogUnknownRefFilter


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

