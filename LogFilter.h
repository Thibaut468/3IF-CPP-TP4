/*************************************************************************
                     LogFilter  -  Filtre de Log
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par GRAVEY Thibaut & CHEN Gong
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LogFilter> (fichier LogFilter.h) ----------------
#if ! defined ( LOGFILTER_H )
#define LOGFILTER_H

//--------------------------------------------------- Interfaces utilisées
#include "LogElement.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogFilter>
// Classe abstraite et non instanciable (méthode virtuelle pure)
// Définissant la base des filtres pour LogElement.
// Classe réutilisable, à laquelle on peut ajouter de nombreux filtres
// grâce au concept d'héritage
//------------------------------------------------------------------------

class LogFilter
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual bool Authorize(LogElement & le) const = 0;
    // Mode d'emploi:
    // Renvoi vrai si le critère du filtre est respecter et le LogElement passe, faux sinon
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    virtual LogFilter & operator = ( const LogFilter & unLogFilter );
    // Mode d'emploi :
    // Surcharger pour éviter son utilisation. On ne souhaite pas qu'un filtre s'affecte.
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    LogFilter ( const LogFilter & unLogFilter );
    // Mode d'emploi (constructeur de copie) :
    // /
    // Contrat :
    //

    LogFilter ( );
    // Mode d'emploi :
    // /
    // Contrat :
    //

    virtual ~LogFilter ( );
    // Mode d'emploi :
    // /
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <LogFilter>

#endif // LOGFILTER_H

