/*************************************************************************
                           StringList  -  une classe étant une liste de chaînes de caractères
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <StringList> (fichier StringList.h) ----------------
#if ! defined ( STRINGLIST_H )
#define STRINGLIST_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct StringNode {
    const char *str;
    StringNode *next;
};

//------------------------------------------------------------------------
// Rôle de la classe <StringList>
/* Classe qui implémente pareil comme la classe TrajetList la structure de donnée nommé “liste simplement chaînée” qui va cette fois stocker non des trajets mais les chaînes de caractères.
*/

//------------------------------------------------------------------------

class StringList
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void add ( const char *s );
    bool contains ( const char *s );

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    StringList (  );
    virtual ~StringList (  );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    StringNode *head;

};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // StringList_H
