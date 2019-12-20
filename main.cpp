#include "Catalogue.h"

#include <iostream>
using namespace std;

int main()
{
    Catalogue * catalogue = new Catalogue();
    while(1)
    {
        cout << "menu" << endl;
        cout << "\t1: afficher les trajets" << endl;
        cout << "\t2: ajouter trajet simple" << endl;
        cout << "\t3: ajouter trajet composé" << endl;
        cout << "\t4: trouver chemin simple" << endl;
        cout << "\t5: trouver chemin complexe" << endl;
        cout << "\t6: Save" << endl;
        cout << "\t0: quitter" << endl;
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
                cout << "All (simple) routes from " << villeDepart << " to " << villeArrivee << ":" << endl;
                catalogue->findRoute( (const char *) villeDepart, (const char *) villeArrivee);
                cout << endl;
                break;
            case 5:
                char villeDepartC[100];
                char villeArriveeC[100];
                cout << "Ville de départ : ";
                cin >> villeDepartC;
                cout << "Ville d'arrivée : ";
                cin >> villeArriveeC;
                cout << "All (complex) routes from " << villeDepartC << " to " << villeArriveeC << ":" << endl;
                catalogue->findRouteComp(villeDepartC, villeArriveeC);
                cout << endl;
                break;
            case 6:
                //catalogue->saveType("TS");
                catalogue->OutputFile();
                break;
            default:
                cout << "choix incorrect" << endl;
                continue ;
        }
    }
    fin:
        delete(catalogue);
        return 0;
}
