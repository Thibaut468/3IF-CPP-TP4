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
//
{
    return infos;
} //----- Fin de GetInfos


//------------------------------------------------- Surcharge d'opérateurs
LogElement & LogElement::operator = ( const LogElement & unLogElement )
// Algorithme :
//
{
} //----- Fin de operator =

ostream & operator << (ostream & os, LogElement & el)
// Algorithme :
//
{
    os << el.GetInfos().IP << " " << el.GetInfos().userLogName << " " << el.GetInfos().authentificatedUser << " ";
    os << "[" << el.GetInfos().date << "] " << el.GetInfos().request << "\" " << el.GetInfos().statusCode << " ";
    os << el.GetInfos().dataQuantity << " \"" << el.GetInfos().referer << "\" \"" <<  el.GetInfos().idNavigateur;
    os << "\"";

    return os;
} //----- Fin de operator <<


//-------------------------------------------- Constructeurs - destructeur
LogElement::LogElement ( const LogElement & unLogElement )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LogElement>" << endl;
#endif
} //----- Fin de LogElement (constructeur de copie)


LogElement::LogElement (const Informations & i) : infos(i)
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de <LogElement>" << endl;
#endif
} //----- Fin de LogElement


LogElement::~LogElement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LogElement>" << endl;
#endif
} //----- Fin de ~LogElement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

