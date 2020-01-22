/*************************************************************************
                   LogTimeFilter  -  Filtre sur l'heure des logs
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par GRAVEY Thibaut & CHEN Gong
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <LogTimeFilter> (fichier LogTimeFilter.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LogTimeFilter.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type LogTimeFilter::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool LogTimeFilter::Authorize(LogElement &le) const
// Algorithme
// On regarde si le log à bien été produit dans le créneau [time, time+interval[.
// On renvoi vrai si c'est le cas, faux sinon.
{
    return ((le.GetInfos().hour >= time) && (le.GetInfos().hour < (time+interval)));
} // ---- Fin de Authorize

//------------------------------------------------- Surcharge d'opérateurs
LogTimeFilter & LogTimeFilter::operator = ( const LogTimeFilter & unLogTimeFilter )
// Algorithme :
// Copie simple de chaque attribut dans le nouvel objet, en évitant le cas ltf1=ltf1
{
    if(this!=&unLogTimeFilter)
    {
        time = unLogTimeFilter.time;
        interval = unLogTimeFilter.interval;
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

LogTimeFilter::LogTimeFilter ( const LogTimeFilter & unLogTimeFilter )
// Algorithme :
// /
{

    time=unLogTimeFilter.time;
    interval=unLogTimeFilter.interval;

#ifdef MAP
    cout << "Appel au constructeur de copie de <LogTimeFilter>" << endl;
#endif
} //----- Fin de LogTimeFilter (constructeur de copie)

LogTimeFilter::LogTimeFilter (int t, int inter) : LogFilter(), time(t), interval(inter)
// Algorithme :
// /
{
#ifdef MAP
    cout << "Appel au constructeur de <LogTimeFilter>" << endl;
#endif
} //----- Fin de LogTimeFilter


LogTimeFilter::~LogTimeFilter ( )
// Algorithme :
// /
{
#ifdef MAP
    cout << "Appel au destructeur de <LogTimeFilter>" << endl;
#endif
} //----- Fin de ~LogTimeFilter


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

