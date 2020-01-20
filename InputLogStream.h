/*************************************************************************
       InputLogStream  -  Gestion d'un log en flux d'entrée fichier
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par GRAVEY Thibaut & CHEN Gong
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <InputLogStream> (fichier InputLogStream.h) ----------------
#if ! defined ( INPUTLOGSTREAM_H )
#define INPUTLOGSTREAM_H

//--------------------------------------------------- Interfaces utilisées

#include <fstream>
#include <vector>
#include "LogElement.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <InputLogStream>
// Cette classe correspond à une des classes réutilisable de notre application
// Cette dernère hérite de la classe ifstream, permettant la gestion d'un flux d'entrée
// et plus particulièrement d'un fichier avec ses indicateurs de fin de fichiers etc
// Elle contient donc toutes les possibilités offertes par ifstream et fournit une
// surcharge de l'opérateur >> pour venir récuperer une ligne de LOG sous la forme d'un
// LogElement, contenant toutes les informations nécessaires. Cette instance n'est pas copiable.
//------------------------------------------------------------------------

class InputLogStream : public ifstream
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string & GetServerUrl();
    // Mode d'emploi :
    // Renvoi l'URL du serveur de log apache (éviter la redondance de l'information dans le referer)
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    InputLogStream & operator = (const InputLogStream & uniflogstream );
    // Mode d'emploi :
    // Surcharge de l'opérateur = implémenté de façon à le désactiver. Un flux ne se copie pas.
    // Contrat :
    //

    friend InputLogStream & operator >> (InputLogStream & ils, LogElement & le);
    // Mode d'emploi :
    // Surcharge de l'opérateur >> pour la lecture d'une ligne de log vers un LogElement
    // Contrat :
    // Le flux doit être ouvert


//-------------------------------------------- Constructeurs - destructeur

    InputLogStream (const string & cheminAcces, const string & url = "");
    // Mode d'emploi :
    // Accède au fichier fournit en paramètre et l'ouvre. L'URL permet de sélectionner le serveur de log apache.
    // Contrat :
    //

    virtual ~InputLogStream ( );
    // Mode d'emploi :
    // /
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    InputLogStream (const InputLogStream & uniflogstream );
    // Mode d'emploi (constructeur de copie) :
    // Non utilisable
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés

    string serverURL;

};

//-------------------------------- Autres définitions dépendantes de <InputLogStream>

#endif // INPUTLOGSTREAM_H

