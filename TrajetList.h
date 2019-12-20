/*************************************************************************
                           TrajetList  -  une liste chaînée de trajets
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetList> (fichier TrajetList.h) ----------------
#if ! defined ( TRAJETLIST_H )
#define TRAJETLIST_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct Node {
    Trajet *trajet;
    Node *next;
};

//------------------------------------------------------------------------
// Rôle de la classe <TrajetList>
/* Cette classe est une implémentation de la structure de donnée nommée “liste simplement chaînée”.
   Elle comporte des méthodes permettant de manipuler aisément les données contenues dans la liste chaînée.
   Parmi les attributs on compte un pointeur vers la première cellule de la liste chaînée (du type Node).
*/

//------------------------------------------------------------------------

class TrajetList
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void ajouterTete ( Trajet *trajet );
    void ajouterQueue ( Trajet *trajet );
    Trajet * premier (  );
    Trajet * dernier (  );
    void afficher (  );
    void deleteFrom ( const char *depart );
    void destroy ( Node *node );
    void OutputFile();
    string getFormat();

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    TrajetList (  );
    virtual ~TrajetList (  );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Node *head;

};

//-------------------------------- Autres définitions dépendantes de <TrajetList>

#endif // TrajetList_H
