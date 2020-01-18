/*************************************************************************
                           States  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <States> (fichier States.h) ----------------
#if ! defined ( States_H )
#define States_H

//--------------------------------------------------- Interfaces utilisées
#include "LogElement.h"
#include <map>
#include <utility>
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef map<string , int> Map_Referers_NbHit;
typedef pair < Map_Referers_NbHit ,int  > Pair_MapReferers_NbHitTotal;   // on ne cree pas cette instance
typedef map<string, Pair_MapReferers_NbHitTotal>  Map_Cibles_Pairs;

typedef vector<string> CiblesTop10;
//------------------------------------------------------------------ Define
//les consignes ci-dessous sont pour rendre le code plus comprehensible
//consigne pour type Map_Cibles_Pairs
#define NameCible first
#define Pair second
//consigne pour type Pair_MapReferers_NbHitTotal
#define MapReferers first
#define NbHitTotal second
//consigne pour type Map_Referers_NbHit
#define NameRefere first
#define NbHit second


//------------------------------------------------------------------------
// Rôle de la classe <States>
//
//
//------------------------------------------------------------------------

class States
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void AjouterInfo (Informations info);
    CiblesTop10 FindTop10();
    void AffichageTop10();

//------------------------------------------------- Surcharge d'opérateurs
    //States & operator = ( const States & unStates );
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend ostream & operator << (ostream & os, States & unState);
    // Mode d'emploi :
    //
    // Contrat :
    //
    Map_Cibles_Pairs & GetMapCibles();
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    States ( const States & unStates );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    States ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~States ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Map_Cibles_Pairs MapCibles;

};
//-------------------------------- Autres définitions dépendantes de <States>

#endif // States_H
