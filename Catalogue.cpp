/*************************************************************************
                           Catalogue  -  une classe étant une liste de trajets avec des méthodes spécifiques en plus
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
#include "StringList.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
/* Une méthode permettant de rajouter un trajet simple dans le catalogue */
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
    this->ajouterQueue ( new TrajetSimple ( (const char *) villeDepart, (const char *) villeArrivee, (const char *) modeTransport ) );
}
/* Une méthode permettant de rajouter un trajet composé dans le catalogue */
void Catalogue::ajouterTrajetCompose (  )
{
    char villeDepart[100];
    char villeArrivee[100];
    char modeTransport[20];
    cout << "Ville de départ : ";
    cin >> villeDepart;
    cout << "Ville d'arrivée : ";
    cin >> villeArrivee;
    TrajetList *trajets = new TrajetList (  );
    char villeArret[100];
    while ( strcmp ( villeArret, villeArrivee ) != 0 )
    {
        cout << "Taper la ville d'arrêt (pour finir donner la ville d'arrivée) : ";
        cin >> villeArret;
        cout << "Mode de transport : ";
        cin >> modeTransport;
        trajets->ajouterQueue( new TrajetSimple( (const char *) villeDepart, (const char *) villeArret, (const char *) modeTransport ) );
        strcpy ( villeDepart, villeArret );
    }
    this->ajouterQueue ( new TrajetCompose( trajets ) );
}
/* Une méthode affichant dans le terminal tous les trajets contenus dans le catalogue - la même chose que listerTrajets */
void Catalogue::listerTrajets (  )
{
    this->afficher (  );
}
/* Une méthode permettant d'afficher l'objet dans le terminal */
void Catalogue::afficher (  )
{
    Node *current = this->head;
    while ( current != nullptr )
    {
        current->trajet->afficher (  );
        cout << "\n";
        current = current->next;
    }
}
/* Recherche simple, prend en paramètre les noms de villes de départ et d'arrivée */
void Catalogue::findRoute ( const char *depart, const char *arrive )
{
    Node *current = this->head;
    while ( current != nullptr )
    {
        if ( strcmp ( current->trajet->getVilleDepart (  ), depart ) == 0 && strcmp ( current->trajet->getVilleArrivee(), arrive ) == 0 )
        {
            current->trajet->afficher (  );
        }
        current = current->next;
    }
}
/* Recherche complexe, prend en paramètre les noms de villes de départ et d'arrivée */
void Catalogue::findRouteComp ( const char *depart, const char *arrive )
{
    StringList *visited = new StringList (  );
    TrajetList *path = new TrajetList (  );
    dfs ( depart, arrive, visited, path );
    delete ( visited );
    delete ( path );
}
/* Méthode implémentant l'algorithme de parcours en profondeur - utilisée par la méthode findRouteComp */
void Catalogue::dfs ( const char *current, const char *search, StringList *visited, TrajetList *path )
{
    if ( strcmp ( current, search ) == 0 )
    {
        path->afficher (  );
    } else
    {
        visited->add ( current );
    }
    Node *temp = this->head;
    while ( temp != nullptr )
    {
        if ( strcmp ( temp->trajet->getVilleDepart(), current ) == 0 && !visited->contains( temp->trajet->getVilleArrivee (  ) ) )
        {
            path->ajouterQueue ( new Trajet ( current, temp->trajet->getVilleArrivee (  ) ) );
            dfs ( temp->trajet->getVilleArrivee(), search, visited, path );
            path->deleteFrom ( current );
        }
        temp = temp->next;
    }
}
void Catalogue::saveAll () {
    // OutputFile(this);
}
void Catalogue::saveType(const string t) {
    /*TrajetList * tl = new TrajetList();
    Node *current = this->head;
    while ( current != nullptr )
    {
        if(t == current->trajet->name()) {
            tl->ajouterQueue(current->trajet);
        }
        current = current->next;
    }
    // tl->output();
    delete(tl);*/
}
void Catalogue::saveSpecific(const string depart, const string arrive) {
    /*TrajetList * tl = new TrajetList();
    Node *current = this->head;
    while ( current != nullptr )
    {
        if(depart != "" && arrive == "") {
            if(current->trajet->getVilleDepart() == depart) {
                tl->ajouterQueue(current->trajet);
            }
        } else if(depart == "" && arrive != "") {
            if(current->trajet->getVilleArrivee() == arrive) {
                tl->ajouterQueue(current->trajet);
            }
        } else if(depart != "" && arrive != "") {
            if((current->trajet->getVilleDepart() == depart)
            && (current->trajet->getVilleArrivee() == arrive)) {
                tl->ajouterQueue(current->trajet);
            }
        }
        current = current->next;
    }
    // tl->output();
    delete(tl);*/
}
void Catalogue::saveInterval(int n, int m) {
    TrajetList * tl = new TrajetList();
    int counter = 0;
    Node *current = this->head;
    while ( current != nullptr )
    {
        if(counter >= n && counter <= m) {
            tl->ajouterQueue(current->trajet);
        }
        counter++;
        current = current->next;
    }
    // tl->output();
    delete(tl);
}
/* Méthode restituant les trajets à partir d'un fichier dont le nom est passé en paramètre */
void Catalogue::restituerTrajets ( const char *nomfichier )
{
    ifstream fluxlecture;
    fluxlecture.open("fichier.trajets");
        
    if (fluxlecture) {
        for (string ligne; getline(fluxlecture, ligne);) {
            auto start = 0;
            auto end = ligne.find("#", start);
            string typeTrajet = ligne.substr(start, end);
            start = typeTrajet.length() + 1;
            cout << typeTrajet << endl;
            if (typeTrajet == "TS") {
                string attributs[3];
                int i = 0;
                while (end != ligne.length() - 1) {
                    end = ligne.find(":", start);
                    attributs[i] = ligne.substr(start, end - start);;
                    start += attributs[i].length() + 1;
                    i++;
                }
                this->ajouterQueue(new TrajetSimple(attributs[0].c_str(), attributs[1].c_str(), attributs[2].c_str()));
            } else {
                string attribut;
                while (end != ligne.length() - 1) {
                    end = ligne.find(":", start);
                    string attribut = ligne.substr(start, end - start);
                    start += attribut.length() + 1;
                    cout << attribut << endl;
                    if (end + 1 == ligne.find("&", start)) {
                        start++;
                        cout << "---" << endl;
                    }
                }
            }
        }
    } else {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture !" << endl;
    }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
