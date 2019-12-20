/*************************************************************************
                           TrajetSimple  -  une classe représentant un trajet simple qui comporte 3 attributs : villeDepart, villeArrivee et modeTransport
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
/* Une méthode permettant d'afficher l'objet dans le terminal */
void TrajetSimple::afficher (  )
{
    cout << "de " << villeDepart << " à " << villeArrivee << " en " << modeTransport;
}
/* Un getteur permettant d'obtenir la valeur de l'attribut protégé modeTransport */
const char * TrajetSimple::getModeTransport (  )
{
    return modeTransport;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/* Un constructeur par recopie de la classe TrajetSimple */
TrajetSimple::TrajetSimple ( TrajetSimple * original ) : Trajet ( original->villeDepart, original->villeArrivee )
{
    #ifdef MAP
        cout << "Appel au constructeur par recopie de <TrajetSimple>" << endl;
    #endif
    this->modeTransport = original->modeTransport;
}
/* Un constructeur de la classe TrajetSimple */
TrajetSimple::TrajetSimple ( const char *villeDepart, const char *villeArrivee, const char *modeTransport ) : Trajet ( villeDepart, villeArrivee )
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
    char *tempModeTransport = new char[ strlen ( modeTransport ) ];
    strcpy ( tempModeTransport, modeTransport );
    this->modeTransport = tempModeTransport;
}
/* Destructeur de la classe TrajetSimple */
TrajetSimple::~TrajetSimple (  )
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetSimple>" << endl;
    #endif
    delete ( modeTransport );
}

string TrajetSimple::name() const {
    return "TS";
}

const string TrajetSimple::format()
{

    string vd(villeDepart);
    string va(villeArrivee);
    string mt(modeTransport);
    string s = "TS#" + vd + ":" + va +":" + mt + ":";
    //+":"+str(villeArrivee)+":"+str(modeTransport)+":"


    return s;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
