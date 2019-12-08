#include <iostream>
#include <cstring>

#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "StringList.h"

using namespace std;

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
    TrajetList * results =  new TrajetList();
    StringList * visited = new StringList();
    TrajetList * path = new TrajetList();

    dfs( depart, arrive, visited, results, path);
    return results;
}

void Catalogue::dfs( const char * current, const char * search, StringList* visited, TrajetList * results, TrajetList * path)
{
    if(strcmp(current,search) == 0) {
        TrajetCompose * result = new TrajetCompose(path);
        result->afficher();
        cout << endl;
    } else {
        visited->add(current);
    }
    Node *temp = this->head;
    while (temp != nullptr)
    {
        if( strcmp(temp->trajet->getVilleDepart(),current) == 0
            && !visited->contains(temp->trajet->getVilleArrivee()))
        {
            path->ajouterQueue(new Trajet(current, temp->trajet->getVilleArrivee()));
            dfs(temp->trajet->getVilleArrivee(), search, visited, results, path);
            path->deleteFrom(current);
        }
        temp = temp->next;
    }
}
