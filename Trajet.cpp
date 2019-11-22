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
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Trajet::afficher (  )
{
    cout << "Ville départ : " << villeDepart << "\n";
    cout << "Ville arrivée : " << villeArrivee << "\n";
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
