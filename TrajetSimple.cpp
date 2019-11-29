/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::afficher (  )
{
    cout << "de " << villeDepart << " à " << villeArrivee << " en " << modeTransport;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/*TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
{
    Trajet ( unTrajetSimple.villeDepart, unTrajetSimple.villeArrivee );   
    this->modeTransport = unTrajetSimple.modeTransport;
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
    #endif
}*/

TrajetSimple::TrajetSimple ( const char *villeDepart, const char *villeArrivee, const char *modeTransport ) : Trajet ( villeDepart, villeArrivee )
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
    char *tempModeTransport = new char[strlen(modeTransport)];
    strcpy(tempModeTransport, modeTransport);
    this->modeTransport = tempModeTransport;
}

TrajetSimple::~TrajetSimple ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetSimple>" << endl;
    #endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
