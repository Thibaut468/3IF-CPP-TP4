/*************************************************************************
                     LogTimeFilter  -  description
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par GRAVEY Thibaut & CHEN Gong
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LogTimeFilter> (fichier LogTimeFilter.h) ----------------
#if ! defined ( LOGTIMEFILTER_H )
#define LOGTIMEFILTER_H

//--------------------------------------------------- Interfaces utilisées
#include "LogFilter.h"
#include "LogElement.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogTimeFilter>
//
//
//------------------------------------------------------------------------

class LogTimeFilter : public LogFilter
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool Authorize(LogElement & le) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    LogTimeFilter & operator = (const LogTimeFilter & unLogTimeFilter );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    LogTimeFilter (const LogTimeFilter & unLogTimeFilter );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LogTimeFilter (int t = 0, int inter = 0);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LogTimeFilter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    int time;
    int interval;

};

//-------------------------------- Autres définitions dépendantes de <LogTimeFilter>

#endif // TIMEFILTER_H

