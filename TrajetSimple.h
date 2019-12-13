/*************************************************************************
                           TrajetSimple  -  une classe représentant un trajet simple qui comporte 3 attributs : villeDepart, villeArrivee et modeTransport
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
/* Spécialisation de la classe Trajet.
   Elle comporte toutes les méthodes et attributs du parent en spécifiant en plus des attributs et méthodes spécifiques à elle-même.
   Ainsi TrajetSimple comprend un attribut en plus par rapport à son parent (un pointeur vers une chaîne de caractères - modeTransport).
   Une méthode d’affichage afficher() a aussi été redéfinie pour cette classe fille.
   Cette redéfinition est une représentation de la notion nommé “surcharge”.
   Dans la classe parente la déclaration de la méthode afficher() a été précédé par le mot-clé virtual ce qui signifie qu’elle sera accessible aussi pour les classe dérivant de celle-ci.
*/

//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void afficher (  );
    const char * getModeTransport (  );

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const char *villeDepart, const char *villeArrivee, const char *modeTransport );
    TrajetSimple ( TrajetSimple * original );
    virtual ~TrajetSimple (  );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    const char *modeTransport;

};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TrajetSimple_H
