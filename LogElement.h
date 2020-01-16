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
    int day;
    string month;
    int year;
    int hour;
    int minute;
    int second;
    string GMT;
    string action;
    string URL;
    string protocol;
    int statusCode;
    int dataQuantity;
    string referer;
    string idNavigateur;

    Informations(string ip="",string uln="",string au="",int j = 0, string mo="", int y = 0, int h = 0, int m = 0, int s = 0, string dec="", string act="", string u="", string p="",int code = 0, int qty = 0, string ref = "", string id="")
        : IP(ip), userLogName(uln), authentificatedUser(au), day(j), month(mo), year(y), hour(h), minute(m), second(s), GMT(dec), action(act), URL(u), protocol(p), statusCode(code), dataQuantity(qty), referer(ref), idNavigateur(id) {}
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

