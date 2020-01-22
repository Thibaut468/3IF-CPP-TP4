/*************************************************************************
         LogExtensionFilter  -  Filtre sur les extensions de documents
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
// Hérite de la classe LogFilter. Classe réutilisable permettant de refuser certaines
// extension dans les LogElements (les filtrer). On vient ajouter les différentes extensions à refuser, que l'on
// peut aussi retirer du filtre ensuite.
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
    // Renvoi vrai si le LogElement passe le filtre, faux sinon.
    // Contrat :
    //

    void AddExtension(string ext);
    // Mode d'emploi :
    // Ajoute une extension au filtre
    // Contrat :
    // Sous le format ".ext" avec ext l'extension voulue

    bool RemoveExtension(string ext);
    // Mode d'emploi
    // Retire une extension au filtre
    // Renvoi vrai si elle a bien été retirée
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    LogExtensionFilter & operator = (const LogExtensionFilter & unLogExtensionFilter );
    // Mode d'emploi :
    // Surcharge de l'opérateur d'affectation copiant les attributs de façon basique
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    LogExtensionFilter (const LogExtensionFilter & unLogExtensionFilter );
    // Mode d'emploi (constructeur de copie) :
    // /
    // Contrat :
    //

    LogExtensionFilter (vector<string> & ext);
    // Mode d'emploi :
    // On donne en paramètre un vector contenant les premieres extensions à refuser
    // Contrat :
    //

    virtual ~LogExtensionFilter ( );
    // Mode d'emploi :
    // /
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

