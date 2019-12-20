/*************************************************************************
                           Catalogue  -  une classe étant une liste de trajets avec des méthodes spécifiques en plus
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "TrajetList.h"
#include "TrajetCompose.h"
#include "StringList.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
/* Classe pour la gestion des trajets (ajout et traitement sur les trajets déjà stockées dans la mémoire).
   Elle hérite de la classe TrajetList qui est l’implémentation de la liste chaînée.
   Catalogue dispose alors déjà de toutes les méthodes de celle-ci mais comprend en plus des méthodes additionnelles spécifiques pour augmenter le niveau de spécialisation et effectuer les opérations plus adaptés sur les trajets.
*/

//------------------------------------------------------------------------

class Catalogue : public TrajetList
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void ajouterTrajetSimple (  );
    void ajouterTrajetCompose (  );
    void listerTrajets (  );
    void afficher (  );
    void findRoute ( const char *depart, const char *arrive );
    void findRouteComp ( const char *depart, const char *arrive );
    void dfs ( const char *current, const char *search, StringList *visited, TrajetList *path );
    void saveAll (  );
    void saveType( const std::string t);
    void saveSpecific( const std::string depart, const std::string arrive);
    void restituerTrajets ( const char *nomFichier );

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H