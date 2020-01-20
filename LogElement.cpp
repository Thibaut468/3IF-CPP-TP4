/*************************************************************************
       LogElement  -  Stockage des informations d'une ligne de log
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par GRAVEY Thibaut & CHEN Gong
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <LogElement> (fichier LogElement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LogElement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type LogElement::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

Informations & LogElement::GetInfos()
// Algorithme :
// /
{
    return infos;
} //----- Fin de GetInfos


//------------------------------------------------- Surcharge d'opérateurs
LogElement & LogElement::operator = ( const LogElement & unLogElement )
// Algorithme :
// Copie simple de chaque attribut dans le nouvel objet, en évitant le cas le1=le1
{
    if(this != &unLogElement)
    {
        infos.IP=unLogElement.infos.IP;
        infos.userLogName=unLogElement.infos.userLogName;
        infos.authentificatedUser=unLogElement.infos.authentificatedUser;
        infos.day=unLogElement.infos.day;
        infos.month=unLogElement.infos.month;
        infos.year=unLogElement.infos.year;
        infos.hour=unLogElement.infos.hour;
        infos.minute=unLogElement.infos.minute;
        infos.second=unLogElement.infos.second;
        infos.GMT=unLogElement.infos.GMT;
        infos.action=unLogElement.infos.action;
        infos.URL=unLogElement.infos.URL;
        infos.protocol=unLogElement.infos.protocol;
        infos.statusCode=unLogElement.infos.statusCode;
        infos.dataQuantity=unLogElement.infos.dataQuantity;
        infos.referer=unLogElement.infos.referer;
        infos.idNavigateur=unLogElement.infos.idNavigateur;
    }
    return *this;
} //----- Fin de operator =

ostream & operator << (ostream & os, LogElement & el)
// Algorithme :
// Utilisation de << du stream pour afficher simplement les valeurs de chaque attribut.
// On reconstitue, dans l'ordre, la ligne de log
// On vient aussi formater les entrées numériques
// On renvoi l'os pour l'enchainement
{
    os << el.GetInfos().IP << " " << el.GetInfos().userLogName << " " << el.GetInfos().authentificatedUser << " ";
    os << "[";

    if(el.GetInfos().day<=9)
    {
        os << "0";
    }
    os << el.GetInfos().day << "/" << el.GetInfos().month << "/" << el.GetInfos().year << ":";

    if(el.GetInfos().hour<=9)
    {
        os << "0";
    }
    os << el.GetInfos().hour << ":";

    if(el.GetInfos().minute<=9)
    {
        os << "0";
    }
    os << el.GetInfos().minute << ":";

    if(el.GetInfos().second<=9)
    {
        os << "0";
    }
    os << el.GetInfos().second << " ";

    os << el.GetInfos().GMT << "] ";
    os << "\"" << el.GetInfos().action << " " << el.GetInfos().URL << " " << el.GetInfos().protocol << "\" ";
    os << el.GetInfos().statusCode << " " << el.GetInfos().dataQuantity;
    os << " \"" << el.GetInfos().referer << "\" \"" <<  el.GetInfos().idNavigateur << "\"";

    return os;
} //----- Fin de operator <<


//-------------------------------------------- Constructeurs - destructeur
LogElement::LogElement ( const LogElement & unLogElement )
// Algorithme :
// /
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LogElement>" << endl;
#endif
} //----- Fin de LogElement (constructeur de copie)


LogElement::LogElement (const Informations & i) : infos(i)
// Algorithme :
// /
{

#ifdef MAP
    cout << "Appel au constructeur de <LogElement>" << endl;
#endif
} //----- Fin de LogElement


LogElement::~LogElement ( )
// Algorithme :
// /
{
#ifdef MAP
    cout << "Appel au destructeur de <LogElement>" << endl;
#endif
} //----- Fin de ~LogElement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

