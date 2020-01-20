/*************************************************************************
                     LogUnknownRefFilter  -  description
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par GRAVEY Thibaut & CHEN Gong
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LogUnknownRefFilter> (fichier LogUnknownRefFilter.h) ----------------
#if ! defined ( LOGUNKNOWNREFFILTER_H )
#define LOGUNKNOWNREFFILTER_H

//--------------------------------------------------- Interfaces utilisées
#include "LogFilter.h"
#include "LogElement.h"
#include <vector>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogUnknownRefFilter>
//
//
//------------------------------------------------------------------------

class LogUnknownRefFilter : public LogFilter
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //LogUnknownRefFilter.h
    // Contrat :
    //

    bool Authorize(LogElement & le) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AddName(string name);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool RemoveName(string name);
    // Mode d'emploi
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    LogUnknownRefFilter & operator = (const LogUnknownRefFilter & unLogUnknownRefFilter );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    LogUnknownRefFilter (const LogUnknownRefFilter & unLogUnknownRefFilter );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LogUnknownRefFilter (vector<string> & name);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LogUnknownRefFilter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    vector<string> unknownName;

};

//-------------------------------- Autres définitions dépendantes de <LogUnknownRefFilter>

#endif // TIMEFILTER_H

