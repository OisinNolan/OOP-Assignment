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

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes
using namespace std;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::afficher (  )
{
    cout << "Ville départ : " << villeDepart << "\n";
    cout << "Ville arrivée : " << villeArrivee << "\n";
    cout << "Moyen de transport : " << modeTransport << "\n";
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

TrajetSimple::TrajetSimple ( const char *villeDepart, const char *villeArrivee, const char *modeTransport ) : Trajet ( villeDepart, villeArrivee ), modeTransport ( modeTransport )
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
}

TrajetSimple::~TrajetSimple ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetSimple>" << endl;
    #endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
