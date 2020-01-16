/*************************************************************************
                     LogExtensionFilter  -  description
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par GRAVEY Thibaut & CHEN Gong
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LogExtensionFilter> (fichier LogExtensionFilter.h) ----------------
#if ! defined ( LOGEXTENSIONFILTER_H )
#define LOGEXTENSIONFILTER_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include "LogFilter.h"
#include "LogElement.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogExtensionFilter>
//
//
//------------------------------------------------------------------------

class LogExtensionFilter : public LogFilter
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

    void AddExtension(string ext);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool RemoveExtension(string ext);
    // Mode d'emploi
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    LogExtensionFilter & operator = (const LogExtensionFilter & unLogExtensionFilter );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    LogExtensionFilter (const LogExtensionFilter & unLogExtensionFilter );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LogExtensionFilter (vector<string> & ext);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LogExtensionFilter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    vector<string> extensions;

};

//-------------------------------- Autres définitions dépendantes de <LogExtensionFilter>

#endif // TIMEFILTER_H

