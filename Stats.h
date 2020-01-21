/*************************************************************************
                           States  -  description
                             -------------------
début                : 21/01/2020
copyright            : (C) 2020 par GRAVEY Thibaut & CHEN Gong
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Stats> (fichier Stats.h) ----------------
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
// Rôle de la classe <Stats>
//
//
//------------------------------------------------------------------------

class Stats
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void AjouterInfo (Informations & info);
    // Mode d'emploi : Pour ajouter une information dans cette classe Stats
    // Contrat :
    //
    void AffichageTop10();
    // Mode d'emploi : Affichage de top 10 cibles les plus consultees.
    //
    // Contrat :
    //
//------------------------------------------------- Surcharge d'opérateurs
    Stats & operator = ( const Stats & unStates );
    // Mode d'emploi :
    //Surchage de l'operateur d'affectation pour interdire l'affectation
    // Contrat :
    //

    friend ostream & operator << (ostream & os, Stats & unStats);
    // Mode d'emploi :
    // pour afficher directement dans main
    // Contrat :
    //

    Map_Cibles_Pairs & GetMapCibles();
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Stats (const Stats & unStats );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Stats ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Stats ( );
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
//-------------------------------- Autres définitions dépendantes de <Stats>

#endif // States_H
