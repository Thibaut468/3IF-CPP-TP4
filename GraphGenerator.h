/*************************************************************************
      GraphGenerateur  -  Générateur de fichier .dot au format GraphViz
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
#include <algorithm>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GraphGenerator>
// Permet de générer, à partir d'informations provenant d'un fichier de logs
// apache et regrouper dans une instance de Stats, un fichier .dot
// sous le format GraphViz représentant sous la forme d'un graphique
// les corrélations entre les cibles et les référents. Et le nombre de hits
// entre les deux (nombre d'accès de la cible depuis le référent).
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
    // Mode d'emploi :
    // Crée un fichier dotName.dot à la racine de l'application à l'aide des stats
    // préalablement inséré dans unMapCibles.
    // Contrat :
    // Avoir préalablement analyser des données via une instance de Stats.

//------------------------------------------------- Surcharge d'opérateurs
    GraphGenerator & operator = ( const GraphGenerator & unGraphGenerateur );
    // Mode d'emploi :
    // Surchage de l'operateur basique de copie d'attributs
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    GraphGenerator (const GraphGenerator & unGraphGenerateur );
    // Mode d'emploi (constructeur de copie) :
    // /
    // Contrat :
    //

    GraphGenerator ( );
    // Mode d'emploi :
    // /
    // Contrat :
    //

    virtual ~GraphGenerator ( );
    // Mode d'emploi :
    // /
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
vector<string> nodes;
};

//-------------------------------- Autres définitions dépendantes de <GraphGenerator>

#endif // GraphGenerateur_H
