/*************************************************************************
                           StringList  -  une classe étant une liste de chaînes de caractères
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <StringList> (fichier StringList.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "StringList.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
/* Une méthode permettant de rajouter une chaîne de caractères dans la liste */
void StringList::add ( const char *s )
{
    StringNode *node = new StringNode (  );
    node->str = s;
    node->next = this->head;
    this->head = node;
}
/* Une méthode retournant une valeur booléenne dépendamment si la chaîne passée en paramètre se trouve ou non dans la liste */
bool StringList::contains ( const char *s )
{
    StringNode *runner = this->head;
    while ( runner != nullptr )
    {
        if ( strcmp ( runner->str, s ) == 0 )
        {
            return true;
        }
        runner = runner->next;
    }
    return false;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/* Un constructeur de la classe StringList */
StringList::StringList (  )
{
    #ifdef MAP
        cout << "Appel au constructeur de <StringList>" << endl;
    #endif
    StringNode *node = nullptr;
    this->head = node;
}
/* Destructeur de la classe StringList */
StringList::~StringList (  )
{
    #ifdef MAP
        cout << "Appel au destructeur de <StringList>" << endl;
    #endif
    while ( head )
    {
        StringNode *old = head;
        head = head->next;
        //delete(old->str);
        delete old;
    }
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
