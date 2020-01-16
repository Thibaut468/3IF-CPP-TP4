/*************************************************************************
                       LogExtensionFilter  -  description
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par GRAVEY Thibaut & CHEN Gong
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <LogExtensionFilter> (fichier LogExtensionFilter.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LogExtensionFilter.h"
#include <algorithm>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type LogExtensionFilter::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool LogExtensionFilter::Authorize(LogElement &le) const
// Algorithme
//
{
    if(le.GetInfos().URL.find_last_of('.') == string::npos) //Pas d'extension
    {
        return true;
    }

    return (find(extensions.begin(),extensions.end(),le.GetInfos().URL.substr(le.GetInfos().URL.find_last_of('.')))==extensions.end());
} // ---- Fin de Authorize

void LogExtensionFilter::AddExtension(string ext)
// Algorithme
//
{
    extensions.push_back(ext);
} // ---- Fin de AddExtension

bool LogExtensionFilter::RemoveExtension(string ext)
// Algorithme
//
{
    vector<string>::iterator pos = find(extensions.begin(),extensions.end(),ext);
    if(pos!=extensions.end())
    {
        extensions.erase(pos);
        return true;
    }

    return false;
} // ---- Fin de RemoveExtension

//------------------------------------------------- Surcharge d'opérateurs

LogExtensionFilter& LogExtensionFilter::operator=(const LogExtensionFilter &unLogExtensionFilter)
// Algorithme :
//
{
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

LogExtensionFilter::LogExtensionFilter ( const LogExtensionFilter & unLogExtensionFilter )
// Algorithme :
//
{

    for(vector<string>::const_iterator it=unLogExtensionFilter.extensions.begin(); it!=unLogExtensionFilter.extensions.end(); ++it)
    {
        extensions.emplace_back((*it));
    }

#ifdef MAP
        cout << "Appel au constructeur de copie de <LogExtensionFilter>" << endl;
#endif
} //----- Fin de LogExtensionFilter (constructeur de copie)

LogExtensionFilter::LogExtensionFilter(vector<string> & ext) : LogFilter()
// Algorithme :
//
{

    for(vector<string>::iterator it=ext.begin(); it!=ext.end(); ++it)
    {
        extensions.push_back(*it);
    }

#ifdef MAP
    cout << "Appel au constructeur de <LogExtensionFilter>" << endl;
#endif
} //----- Fin de LogExtensionFilter


LogExtensionFilter::~LogExtensionFilter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LogExtensionFilter>" << endl;
#endif
} //----- Fin de ~LogExtensionFilter


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
