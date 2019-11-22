#include "Trajet.h"
#include "TrajetSimple.h"
#include "ListTrajet.h"

int main (  )
{
    Trajet * t0 = new Trajet( "Paris", "Lille" );
    TrajetSimple * t1 = new TrajetSimple( "Paris", "Lille", "Voiture" );
    
    ListTrajet * list = new ListTrajet();
    list->push(t0);
    list->push(t1);
    list->print();


    return 0;
}