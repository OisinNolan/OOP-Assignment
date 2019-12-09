//#include "Trajet.h"
//#include "TrajetSimple.h"
//#include "TrajetCompose.h"
#include "Catalogue.h"
// juste pour les tests
#include <iostream>

using namespace std;

int main (  )
{
    Catalogue * catalogue = new Catalogue();
    TrajetList* tl = new TrajetList();

    while(1)
    {
        cout << "menu" << endl;
        cout << "\t1: afficher les trajets" << endl;
        cout << "\t2: ajouter trajet simple" << endl;
        cout << "\t3: ajouter trajet compose" << endl;
        cout << "\t4: trouver chemin simple" << endl;
        cout << "\t5: trouver chemin complex" << endl;
        cout << "\t0: quitter " << endl;
        int choix;
        scanf("%d", &choix);
        switch(choix)
        {
        case 0:
            goto fin;
        case 1:
            catalogue->listerTrajets();
            break;
        case 2:
            catalogue->ajouterTrajetSimple();
            break;
        case 3:
            catalogue->ajouterTrajetCompose();
            break;
        case 4:
            char villeDepart[100];
            char villeArrivee[100];
            cout << "Ville de départ : ";
            cin >> villeDepart;
            cout << "Ville d'arrivée : ";
            cin >> villeArrivee;
            cout << "Mode de transport : ";
            tl = catalogue->findRoute( (const char *) villeDepart, (const char *) villeArrivee);
            tl->afficher();
            cout<<endl;
            break;
        case 5:
            char villeDepartC[100];
            char villeArriveeC[100];
            cout << "Ville de départ : ";
            cin >> villeDepartC;
            cout << "Ville d'arrivée : ";
            cin >> villeArriveeC;
            catalogue->findRouteComp(villeDepartC, villeArriveeC);
            break;
        default:
            cout << "choix incorrect" << endl;
            continue ;
        }
    }
    fin:
    return 0;
}
