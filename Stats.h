/*************************************************************************
      Stats  -  Classe gérant les statistiques de l'analyse de logs apache
                             -------------------
début                : 21/01/2020
copyright            : (C) 2020 par GRAVEY Thibaut & CHEN Gong
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Stats> (fichier Stats.h) ----------------
#if ! defined ( STATS_H )
#define STATS_H

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
// Cette classe contient notre structure de données principale et permet
// le stockage des différentes informations récupérés via l'analyse d'un fichier de
// logs apache. On peut ainsi en ressortir le classement des 10 cibles les plus consultées.
// Cette classe prépare aussi les données à la création d'un graphique sous le format GraphViz
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
    // Mode d'emploi :
    // Ajouter une information entre cible et référent selon l'information contenu dans un élément de Log
    // Contrat :
    //
    void AffichageTop10();
    // Mode d'emploi :
    // Affichage des 10 cibles les plus consultees sur les données entrés dans l'instance via AjouterInfo
    // Contrat :
    // Avoir rempli l'instance avec les données souhaités au préalable
//------------------------------------------------- Surcharge d'opérateurs
    Stats & operator = ( const Stats & unStats );
    // Mode d'emploi :
    // Surchage de l'operateur d'affectation pour la copie des attributs
    // Contrat :
    //

    friend ostream & operator << (ostream & os, Stats & unStats);
    // Mode d'emploi :
    // Surcharge de l'opérateur << pour faciliter l'affichage sur un ostream
    // Contrat :
    //

    Map_Cibles_Pairs & GetMapCibles();
    // Mode d'emploi :
    // Getter.
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Stats (const Stats & unStats );
    // Mode d'emploi (constructeur de copie) :
    // /
    // Contrat :
    //

    Stats ( );
    // Mode d'emploi :
    // /
    // Contrat :
    //

    virtual ~Stats ( );
    // Mode d'emploi :
    // /
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Map_Cibles_Pairs MapCibles;

};
//-------------------------------- Autres définitions dépendantes de <Stats>

#endif // STATS_H
