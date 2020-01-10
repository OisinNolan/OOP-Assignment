#include "Catalogue.h"

#include <iostream>
#include <cstring>
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
        cout << "\t6: sauvegarder les trajets" << endl;
        cout << "\t7: restituer les trajets" << endl;
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

                char nomFichierW[100];
                cout << "Donner le nom du fichier à écrire : ";
                cin >> nomFichierW;

                cout << "\t10: sauvegarder tout" << endl;
                cout << "\t11: sauvegarder par type" << endl;
                cout << "\t12: sauvegarder par vd/va" << endl;
                cout << "\t13: sauvegarder l'interval" << endl;
                int choixS;
                scanf("%d", &choixS);
                switch(choixS)
                {
                    case 10:
                        catalogue->OutputFile(nomFichierW);
                        break;
                    case 11:
                        {
                        string type = "";
                        cout << "TS ou TC? ";
                        cin >> type;
                        catalogue->saveType( type,nomFichierW );
                        break;
                        }
                    case 12:
                        char villeDepartS[100];
                        char villeArriveeS[100];
                        cout << "Ville de départ : ";
                        cin >> villeDepartS;
                        cout << "Ville d'arrivée : ";
                        cin >> villeArriveeS;
                        catalogue->saveSpecific(villeDepartS,villeArriveeS,nomFichierW);
                        break;
                    case 13:
                        int start;
                        int end;
                        cout << "Donner debut d'interval : ";
                        cin >> start;
                        cout << "Donner fin d'interval : ";
                        cin >> end;
                        catalogue->saveInterval(start,end,nomFichierW  );
                        break;
                    default:
                        catalogue->OutputFile(nomFichierW);
                        break;
                }
                break;
            case 7:
                char nomFichier[100];
                cout << "Donner le nom du fichier à lire : ";
                cin >> nomFichier;
                cout << "Choissisez le scénario : " << endl;
                cout << "\t1: sans critère de séléction" << endl;
                cout << "\t2: selon le type des trajets" << endl;
                cout << "\t3: selon la ville de départ et/ou la ville d'arrivée" << endl;
                cout << "\t4: selon une séléction de trajets" << endl;
                cout << "\t0: annuler la restitution" << endl;
                int scenario;
                scanf("%d", &scenario);
                switch(scenario) {
                    case 0:
                        break;
                    case 1:
                        catalogue->restituerTrajets(nomFichier, 1);
                        break;
                    case 2:
                        catalogue->restituerTrajets(nomFichier, 2);
                        break;
                    case 3:
                        catalogue->restituerTrajets(nomFichier, 3);
                        break;
                    case 4:
                        catalogue->restituerTrajets(nomFichier, 4);
                        break;
                }
                break;
            default:
                cout << "choix incorrect" << endl;
                continue;
        }
    }
    fin:
        delete(catalogue);
        return 0;
}
