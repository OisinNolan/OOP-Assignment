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
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::afficher (  )
{
    trajets->afficher();
}

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

TrajetCompose::TrajetCompose ( TrajetList *trajets ) : Trajet ( trajets->premier()->getVilleDepart(), trajets->dernier()->getVilleArrivee() ), trajets ( trajets )
{
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
