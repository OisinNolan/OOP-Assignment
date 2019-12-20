/*************************************************************************
                           TrajetCompose  -  une classe représentant un trajet composé
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetList.h"
#include "string"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
/* Comme la classe TrajetSimple, TrajetCompose est aussi une spécialisation de la classe Trajet.
   Par rapport à la classe Trajet dans la classe TrajetCompose on retrouve un attribut en plus - un pointeur vers un objet de type TrajetList qui représentera une liste de trajets ainsi que la redéfinition de la méthode aafficher() comme pour la classe TrajetSimple.
*/

//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void afficher (  );

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose ( TrajetList *trajets );
    virtual ~TrajetCompose (  );
    std::string name() const;
    const string format();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    TrajetList *trajets;

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose_H
