/*************************************************************************
       LogElement  -  Stockage des informations d'une ligne de log
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par GRAVEY Thibaut & CHEN Gong
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LogElement> (fichier LogElement.h) ----------------
#if ! defined ( LOG_ELEMENT_H )
#define LOG_ELEMENT_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

struct Informations
{
    string IP;
    string userLogName;
    string authentificatedUser;
    string date;
    string request;
    int statusCode;
    int dataQuantity;
    string referer;
    string idNavigateur;

    Informations(string ip="",string uln="",string au="",string da="",string req="",int code = 0, int qty = 0, string ref = "", string id="")
        : IP(ip), userLogName(uln), authentificatedUser(au), date(da), request(req), statusCode(code), dataQuantity(qty), referer(ref), idNavigateur(id) {}
};

//------------------------------------------------------------------------
// Rôle de la classe <LogElement>
//
//
//------------------------------------------------------------------------

class LogElement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Informations & GetInfos();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    LogElement & operator = ( const LogElement & unLogElement );
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend ostream & operator << (ostream & os, LogElement & el);
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    LogElement ( const LogElement & unLogElement );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    explicit LogElement (const Informations & i = Informations());
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LogElement ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Informations infos;
};

//-------------------------------- Autres définitions dépendantes de <LogElement>

#endif // LOG_ELEMENT_H

