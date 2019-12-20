/*************************************************************************
                           TrajetCompose  -  une classe représentant un trajet composé
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
/* Une méthode permettant d'afficher l'objet dans le terminal */
void TrajetCompose::afficher (  )
{
    trajets->afficher();
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/* Un constructeur de la classe TrajetCompose */
TrajetCompose::TrajetCompose ( TrajetList *trajets ) : Trajet ( trajets->premier()->getVilleDepart(), trajets->dernier()->getVilleArrivee() ), trajets ( trajets )
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif
}
/* Destructeur de la classe TrajetCompose */
TrajetCompose::~TrajetCompose (  )
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetCompose>" << endl;
    #endif
    delete ( trajets );
}

string TrajetCompose::name() const {
    return "TC";
}

const string TrajetCompose::format()
{
    string s = "TC#";
    s += trajets->getFormat();
    return s;
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
