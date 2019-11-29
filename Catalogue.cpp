#include <iostream>
using namespace std;
#include <cstring>

#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
//#include "Trajet.h"

void Catalogue::ajouterTrajetSimple (  )
{
    char villeDepart[100];
    char villeArrivee[100];
    // à utiliser si les constructeur n'ont pas été défini de la parfaite manière
    //char *modeTransport = new char[20];
    char modeTransport[20];
    cout << "Ville de départ : ";
    cin >> villeDepart;
    cout << "Ville d'arrivée : ";
    cin >> villeArrivee;
    cout << "Mode de transport : ";
    cin >> modeTransport;
    this->ajouterQueue( new TrajetSimple( (const char *) villeDepart, (const char *) villeArrivee, (const char *) modeTransport ) );
}

void Catalogue::ajouterTrajetCompose (  )
{
    char villeDepart[100];
    char villeArrivee[100];
    char modeTransport[20];
    cout << "Ville de départ : ";
    cin >> villeDepart;
    cout << "Ville d'arrivée : ";
    cin >> villeArrivee;
    TrajetList *trajets = new TrajetList();
    char villeArret[100];
    while ( strcmp(villeArret, villeArrivee) != 0 ) {
        cout << "Taper la ville d'arrêt (pour finir donner la ville d'arrivée) : ";
        cin >> villeArret;
        cout << "Mode de transport : ";
        cin >> modeTransport;
        trajets->ajouterQueue( new TrajetSimple( (const char *) villeDepart, (const char *) villeArret, (const char *) modeTransport ) );
        strcpy(villeDepart, villeArret);
    }
    this->ajouterQueue( new TrajetCompose( trajets ) );
}

void Catalogue::listerTrajets (  )
{
    this->afficher();
}

void Catalogue::afficher (  )
{
    Node *current = this->head;
    while (current != nullptr) {
        current->trajet->afficher();
        cout << "\n";
        current = current->next;
    }
}
/*Trajet * Catalogue::findRoute(char * depart, char * arrive) {
    Node * current = this->head;
    while(current != 0) {
        if(strcmp(current->trajet->depart, depart) == 0
            &&  strcmp(current->trajet->arrive, arrcatalogue->ajouterTrajetSimple();ive) == 0) {
                return current->trajet;
        }
    }
    return 0;
}*/