/*************************************************************************
                           GraphGenerateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <GraphGenerateur> (fichier GraphGenerateur.h) ----------------
#if ! defined ( GraphGenerateur_H )
#define GraphGenerateur_H

//--------------------------------------------------- Interfaces utilisées
#include "States.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GraphGenerateur>
//
//
//------------------------------------------------------------------------

class GraphGenerateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Generer(Map_Cibles_Pairs & unMapCibles);

//------------------------------------------------- Surcharge d'opérateurs
//    GraphGenerateur & operator = ( const GraphGenerateur & unGraphGenerateur );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    GraphGenerateur ( const GraphGenerateur & unGraphGenerateur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GraphGenerateur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GraphGenerateur ( );
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

//-------------------------------- Autres définitions dépendantes de <GraphGenerateur>

#endif // GraphGenerateur_H
