/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/*TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
{
    villeDepart = unTrajetCompose.villeDepart;
    villeArrivee = unTrajetCompose.villeArrivee;
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
    #endif
}*/

TrajetCompose::TrajetCompose ( char *villeDepart, char *villeArrivee )
{
    villeDepart = villeDepart;
    villeArrivee = villeArrivee;
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif
}

TrajetCompose::~TrajetCompose ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetCompose>" << endl;
    #endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
