/*************************************************************************
       InputLogStream  -  Gestion d'un log en flux d'entrée
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
//
//
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
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    InputLogStream & operator = (const InputLogStream & uniflogstream );
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend InputLogStream & operator >> (InputLogStream & ils, LogElement & le);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    InputLogStream (const string & cheminAcces, const string & url = "");
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~InputLogStream ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    InputLogStream (const InputLogStream & uniflogstream );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés

    string serverURL;

};

//-------------------------------- Autres définitions dépendantes de <InputLogStream>

#endif // INPUTLOGSTREAM_H

