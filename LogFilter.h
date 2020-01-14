/*************************************************************************
                           LogFilter  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LogFilter> (fichier LogFilter.h) ----------------
#if ! defined ( LOGFILTER_H )
#define LOGFILTER_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogFilter>
//
//
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


//------------------------------------------------- Surcharge d'opérateurs
    LogFilter & operator = ( const LogFilter & unLogFilter );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    LogFilter ( const LogFilter & unLogFilter );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LogFilter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LogFilter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <LogFilter>

#endif // LOGFILTER_H

