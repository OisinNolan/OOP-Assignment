#include "Trajet.h"
#include "TrajetSimple.h"

int main (  )
{
    Trajet t0 ( (char *) "Paris", (char *) "Lille" );
    t0.afficher(  );
    
    TrajetSimple t1 ( (char *) "Paris", (char *) "Lille", (char *) "Voiture" );
    t1.afficher(  );
    return 0;
    
    return 0;
}