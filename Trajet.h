/*************************************************************************
                           Trajet  -  commune pour les trajets simples et les trajets composés, représente un trajet générique
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

<<<<<<< HEAD
#include <string>
using namespace std;

=======
>>>>>>> refs/remotes/origin/master
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
/* Implémentation générale d’un trajet.
   L’instance de cette classe dispose de 2 pointeurs vers 2 attributs de type const char (villeDepart et villeArrivee).
   On dispose également des “getteurs” pour ces 2 attributs et une méthode afficher() - uniquement pour les tests.
*/

//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void afficher (  );
    virtual const char * getVilleDepart (  );
    virtual const char * getVilleArrivee (  );
<<<<<<< HEAD
    virtual std::string name() const;
    virtual const string format();
=======
    //virtual std::string name() const;
>>>>>>> refs/remotes/origin/master

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );
    Trajet ( const char *villeDepart, const char *villeArrivee );
    virtual ~Trajet (  );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    const char *villeDepart;
    const char *villeArrivee;

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H
