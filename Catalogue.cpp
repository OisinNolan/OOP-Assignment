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

TrajetList * Catalogue::findRoute(const char * depart,const char * arrive)
{
    TrajetList * results = new TrajetList();

    Node *current = this->head;
    while (current != nullptr) {

        if( strcmp(current->trajet->getVilleDepart(),depart) == 0
        && strcmp(current->trajet->getVilleArrivee(),arrive) == 0 )
        {
            results->ajouterQueue( current->trajet );
        }
        current = current->next;
    }
    return results;
}

TrajetList * Catalogue::findRouteComp(const char * depart,const char * arrive)
{
    TrajetList * results = new TrajetList();
    StringList * visited = new StringList();
    visited->index = 0;
    const char * l[100];
    visited->list = l;

    dfs( depart, visited );
    return results;
}

void Catalogue::dfs( const char * current, StringList* visited)
{
    cout << current << endl;
    visited->list[visited->index] = current;
    visited->index++;
    Node *temp = this->head;
    while (temp != nullptr)
    {
        if( strcmp(temp->trajet->getVilleDepart(),current) == 0)
        {
            bool hasBeenVisited = false;
            for(int i=0; i<visited->index+1;i++ )
            {
                if( strcmp(visited->list[i],current) == 0) hasBeenVisited = true;
            }

            if(!hasBeenVisited )dfs( temp->trajet->getVilleArrivee(),visited);
        }
        temp = temp->next;
    }
}
