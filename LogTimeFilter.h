/*************************************************************************
                 LogTimeFilter  -  Filtre sur l'heure des logs
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
// Hérite de la classe LogFilter. Classe réutilisable permettant de refuser certains LogElements
// (les filtrer) s'ils n'appartiennent pas à un créneau horaire explicitement défini.
// On paramètre le filtre à sa création.
//------------------------------------------------------------------------

class LogTimeFilter : public LogFilter
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //LogTimeFilter.h
    // Contrat :
    //

    bool Authorize(LogElement & le) const;
    // Mode d'emploi :
    // Renvoi vrai si le LogElement passe le filtre, faux sinon.
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    LogTimeFilter & operator = (const LogTimeFilter & unLogTimeFilter );
    // Mode d'emploi :
    // Surcharge de l'opérateur pour rendre nulle son utilisation. On renvoi l'objet en lui même. Un filtre ne s'affecte pas.
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    LogTimeFilter (const LogTimeFilter & unLogTimeFilter );
    // Mode d'emploi (constructeur de copie) :
    // /
    // Contrat :
    //

    LogTimeFilter (int t = 0, int inter = 0);
    // Mode d'emploi :
    // On donne en paramètre les bornes du filtre [t,t+inter[
    // Contrat :
    // 0 <= t+inter <=24

    virtual ~LogTimeFilter ( );
    // Mode d'emploi :
    // /
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

