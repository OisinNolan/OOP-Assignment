#include "Trajet.h"
#include "TrajetSimple.h"

int main (  )
{
    Trajet t0 ( "Paris", "Lille" );
    t0.afficher(  );
    
    TrajetSimple t1 ( "Paris", "Lille", "Voiture" );
    t1.afficher(  );
    return 0;
    
    return 0;
}