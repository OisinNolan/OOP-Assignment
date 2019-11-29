#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
// juste pour les tests
using namespace std;
#include <iostream>


int main (  )
{
    Trajet * t0 = new Trajet( "A", "B" );
    TrajetSimple * t1 = new TrajetSimple( "C", "D", "MT1" );
    Trajet * t2 = new Trajet( "E", "F" );
    Trajet * t3 = new Trajet( "G", "H" );
    
    TrajetList *trajets = new TrajetList();
    trajets->ajouterQueue(t0);
    trajets->ajouterQueue(t1);
    trajets->ajouterQueue(t2);
    trajets->ajouterQueue(t3);
    trajets->afficher();
    /*cout << "#####\n";
    trajets->dernier()->getVilleArrivee();

    TrajetCompose * t4 = new TrajetCompose( trajets );
    t4->afficher();*/

    return 0;
}