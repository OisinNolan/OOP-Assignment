/*************************************************************************
                           Trajet  -  commune pour les trajets simples et les trajets composés
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes
using namespace std;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Trajet::afficher (  )
{
    cout << "de " << villeDepart << " à " << villeArrivee;
}

const char * Trajet::getVilleDepart (  )
{
    return this->villeDepart;
}

const char * Trajet::getVilleArrivee (  )
{
    return this->villeArrivee;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const Trajet & unTrajet )
{
    this->villeDepart = unTrajet.villeDepart;
    this->villeArrivee = unTrajet.villeArrivee;
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Trajet>" << endl;
    #endif
}

Trajet::Trajet ( const char *villeDepart, const char *villeArrivee )
{
    this->villeDepart = villeDepart;
    this->villeArrivee = villeArrivee;
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet>" << endl;
    #endif
}

Trajet::~Trajet ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <Trajet>" << endl;
    #endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
