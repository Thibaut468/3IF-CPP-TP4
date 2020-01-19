/*************************************************************************
                           GraphGenerateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <GraphGenerator> (fichier GraphGenerator.h) ----------------
#if ! defined ( GraphGenerateur_H )
#define GraphGenerateur_H

//--------------------------------------------------- Interfaces utilisées
#include "Stats.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GraphGenerator>
//
//
//------------------------------------------------------------------------

class GraphGenerator
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Generer(Map_Cibles_Pairs & unMapCibles, string & dotName);

//------------------------------------------------- Surcharge d'opérateurs
//    GraphGenerator & operator = ( const GraphGenerator & unGraphGenerateur );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    GraphGenerator (const GraphGenerator & unGraphGenerateur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GraphGenerator ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GraphGenerator ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
vector<string> Nodes;
};

//-------------------------------- Autres définitions dépendantes de <GraphGenerator>

#endif // GraphGenerateur_H
