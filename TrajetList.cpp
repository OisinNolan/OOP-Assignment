/*************************************************************************
                           TrajetList  -  une liste chaînée de trajets
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetList> (fichier TrajetList.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>
#include <fstream>
#include <string>

//------------------------------------------------------ Include personnel
#include "TrajetList.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
/* Permet de rajouter un trajet en tête de la liste */
void TrajetList::ajouterTete ( Trajet *trajet )
{
    Node *node = new Node (  );
    node->trajet = trajet;
    node->next = this->head;
    this->head = node;
}
/* Permet de rajouter un trajet en queue de la liste */
void TrajetList::ajouterQueue ( Trajet *trajet )
{
    Node *node = new Node (  );
    node->trajet = trajet;
    if ( this->head == nullptr )
    {
        this->head = node;
    } else
    {
        node->next = nullptr;
        Node *temp = this->head;
        while ( temp->next != nullptr )
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}
/* Renvoie le premier trajet de la liste */
Trajet * TrajetList::premier (  )
{
    return this->head->trajet;
}
/* Renvoie le dernier trajet de la liste */
Trajet * TrajetList::dernier (  )
{
    Node *temp = this->head;
    while ( temp->next != nullptr )
    {
        temp = temp->next;
    }
    return temp->trajet;
}
/* Une méthode permettant d'afficher l'objet dans le terminal */
void TrajetList::afficher (  )
{
    Node *current = this->head;
    while ( current != nullptr )
    {
        current->trajet->afficher (  );
        if ( current->next != nullptr )
        {
            cout << " - ";
        }
        current = current->next;
    }
}
/* Supprime le trajet dont la ville de départ est celle donnée en argument */
void TrajetList::deleteFrom ( const char * depart )
{
    Node *current = this->head;
    Node *prev = nullptr;
    bool found = false;
    while ( current != nullptr && !found )
    {
        if ( strcmp ( current->trajet->getVilleDepart(), depart ) == 0 )
        {
            found = true;
            if ( prev != nullptr )
            {
                destroy ( current );
                prev->next = nullptr;
            } else
            {
                destroy ( head );
                this->head = nullptr;
            }
        } else
        {
            prev = current;
            current = current->next;
        }
    }
}
/* Supprime la cellule passée en parametre de la liste chaînée */
void TrajetList::destroy ( Node *node )
{
    while (node)
    {
        Node *old = node;
        node = node->next;
        delete ( old->trajet );
        delete old;
    }
}
void TrajetList::OutputFile()
{
    /*ofstream myfile;
    myfile.open ("example.txt");
    Node *current = this->head;
    while ( current != nullptr )
    {
        myfile << current->trajet->format();
        myfile << endl;
        current = current->next;
    }*/
}

string TrajetList::getFormat()
{
    string s ="";
    Node *current = this->head;
    while ( current != nullptr )
    {
        s += current->trajet->format();
        s += "&";
        current = current->next;
    }

    return s;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/* Un constructeur de la classe TrajetList */
TrajetList::TrajetList (  ) {
    Node *node = nullptr;
    this->head = node;
}
/* Destructeur de la classe TrajetList */
TrajetList::~TrajetList (  ) {
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetList>" << endl;
    #endif
    destroy ( head );
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
