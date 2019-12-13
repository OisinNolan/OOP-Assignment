/*************************************************************************
                           Trajet  -  commune pour les trajets simples et les trajets composés, représente un trajet générique
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
/* Une méthode permettant d'afficher l'objet dans le terminal */
void Trajet::afficher (  )
{
    cout << "de " << villeDepart << " à " << villeArrivee;
}
/* Un getteur permettant d'obtenir la valeur de l'attribut protégé villeDepart */
const char * Trajet::getVilleDepart (  )
{
    return this->villeDepart;
}
/* Un getteur permettant d'obtenir la valeur de l'attribut protégé villeArrivee */
const char * Trajet::getVilleArrivee (  )
{
    return this->villeArrivee;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/* Un constructeur par recopie de la classe Trajet */
Trajet::Trajet ( const Trajet & unTrajet )
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Trajet>" << endl;
    #endif
    this->villeDepart = unTrajet.villeDepart;
    this->villeArrivee = unTrajet.villeArrivee;
}
/* Un constructeur de la classe Trajet */
Trajet::Trajet ( const char *villeDepart, const char *villeArrivee )
{
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet>" << endl;
    #endif
    char *tempVilleDepart = new char[ strlen ( villeDepart ) ];
    strcpy ( tempVilleDepart, villeDepart );
    this->villeDepart = tempVilleDepart;
    char *tempVilleArrivee = new char[ strlen ( villeArrivee ) ];
    strcpy ( tempVilleArrivee, villeArrivee );
    this->villeArrivee = tempVilleArrivee;
}
/* Destructeur de la classe Trajet */
Trajet::~Trajet ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <Trajet>" << endl;
    #endif
    delete ( villeDepart );
    delete ( villeArrivee );
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
