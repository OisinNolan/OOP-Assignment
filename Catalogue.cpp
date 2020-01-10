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
#include <climits>

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
void Catalogue::saveType(const string t, const char *nomfichier ) {
    TrajetList * tl = new TrajetList();
    Node *current = this->head;
    while ( current != nullptr )
    {
        if(t == current->trajet->name()) {
            tl->ajouterQueue(current->trajet);
        }
        current = current->next;
    }
    tl->OutputFile( nomfichier );
    delete(tl);
}
void Catalogue::saveSpecific(const string depart, const string arrive, const char *nomfichier) {
    TrajetList * tl = new TrajetList();
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
    tl->OutputFile( nomfichier );
    delete(tl);
}
void Catalogue::saveInterval(int n, int m ,const char *nomfichier) {
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
    tl->OutputFile( nomfichier );
    delete(tl);
}
/* Méthode restituant les trajets à partir d'un fichier dont le nom est passé en paramètre */
void Catalogue::restituerTrajets ( const char *nomfichier, int option )
{
    ifstream fluxlecture;
    fluxlecture.open(nomfichier);

    if (fluxlecture) {
        if (option == 1 || option == 2 || option == 3 || option == 4) {
            int choixtypetrajet = 3;
            if (option == 2) {
                cout << "Choissisez le type des trajets à restituer : " << endl;
                cout << "\t1: trajet simple" << endl;
                cout << "\t2: trajet composé" << endl;
                cout << "\t3: tous les types" << endl;
                cout << "\t0: annuler la restitution" << endl;
                scanf("%d", &choixtypetrajet);
                if (choixtypetrajet == 0) {
                    return;
                }
            }
            int choixvillestrajet = 4;
            char villeDepart[100];
            char villeArrivee[100];
            if (option == 3) {
                cout << "Spécifiez : " << endl;
                cout << "\t1: selon la ville de départ" << endl;
                cout << "\t2: selon la ville d'arrivée" << endl;
                cout << "\t3: selon la ville de départ et d'arrivée" << endl;
                cout << "\t4: peu importe" << endl;
                cout << "\t0: annuler la restitution" << endl;
                scanf("%d", &choixvillestrajet);
                if (choixvillestrajet == 0) {
                    return;
                }
                switch (choixvillestrajet) {
                    case 0:
                        return;
                    case 1:
                        cout << "Ville de départ : ";
                        cin >> villeDepart;
                        break;
                    case 2:
                        cout << "Ville d'arrivée : ";
                        cin >> villeArrivee;
                        break;
                    case 3:
                        cout << "Ville de départ : ";
                        cin >> villeDepart;
                        cout << "Ville d'arrivée : ";
                        cin >> villeArrivee;
                        break;
                }
            }
            int lignedebut = 0;
            int lignefin = INT_MAX;
            if (option == 4) {
                cout << "Donnez le numéro du premier trajet à restituer : ";
                scanf("%d", &lignedebut);
                cout << "Donnez le numéro du dernier trajet à restituer : ";
                scanf("%d", &lignefin);
                while (lignefin < lignedebut) {
                    cout << "L'intervalle doit contenir au moins un élément !";
                    scanf("%d", &lignefin);
                }
            }
            int compteurligne = 0;
            for (string ligne; getline(fluxlecture, ligne);) {
                auto start = 0;
                auto end = ligne.find("#", start);
                string typeTrajet = ligne.substr(start, end);
                start = typeTrajet.length() + 1;
                if (typeTrajet == "TS" && (choixtypetrajet == 1 || choixtypetrajet == 3)) {
                    string attributs[3];
                    int i = 0;
                    while (end != ligne.length() - 1) {
                        end = ligne.find(":", start);
                        attributs[i] = ligne.substr(start, end - start);;
                        start += attributs[i].length() + 1;
                        i++;
                    }
                    if (((choixvillestrajet == 1 && strcmp(villeDepart, attributs[0].c_str()) == 0) || (choixvillestrajet == 2 && strcmp(villeArrivee, attributs[1].c_str()) == 0) || (choixvillestrajet == 3 && strcmp(villeDepart, attributs[0].c_str()) == 0 && strcmp(villeArrivee, attributs[1].c_str()) == 0) || choixvillestrajet == 4) && compteurligne >= lignedebut && compteurligne <= lignefin) {
                        this->ajouterQueue(new TrajetSimple(attributs[0].c_str(), attributs[1].c_str(), attributs[2].c_str()));
                    }
                } else if (typeTrajet == "TC" && (choixtypetrajet == 2 || choixtypetrajet == 3)) {
                    TrajetList *trajets = new TrajetList();
                    string attributs[3];
                    int i = 0;
                    while (end != ligne.length() - 1) {
                        end = ligne.find(":", start);
                        attributs[i] = ligne.substr(start, end - start);
                        start += attributs[i].length() + 1;
                        i++;
                        if (end + 1 == ligne.find("&", start)) {
                            start++;
                            i = 0;
                            trajets->ajouterQueue(new TrajetSimple(attributs[0].c_str(), attributs[1].c_str(), attributs[2].c_str()));
                        }
                    }
                    trajets->ajouterQueue(new TrajetSimple(attributs[0].c_str(), attributs[1].c_str(), attributs[2].c_str()));
                    if (((choixvillestrajet == 1 && strcmp(villeDepart, trajets->premier()->getVilleDepart()) == 0) || (choixvillestrajet == 2 && strcmp(villeArrivee, trajets->dernier()->getVilleArrivee()) == 0) || (choixvillestrajet == 3 && strcmp(villeDepart, trajets->premier()->getVilleDepart()) == 0 && strcmp(villeArrivee, trajets->dernier()->getVilleArrivee()) == 0) || choixvillestrajet == 4) && compteurligne >= lignedebut && compteurligne <= lignefin) {
                        this->ajouterQueue(new TrajetCompose(trajets));
                    }
                }
                compteurligne++;
            }
        } else {
            cout << "ERREUR: Paramètre option n'a pas été spécifiée ou est faux !" << endl;        
        }
    } else {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture !" << endl;
    }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
