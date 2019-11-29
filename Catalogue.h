#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include "TrajetList.h"

class Catalogue : public TrajetList {
    public:
        void ajouterTrajetSimple (  );
        void ajouterTrajetCompose (  );
        void listerTrajets (  );
        void afficher (  );
        //Trajet * findRoute ( char * depart, char * arrive );
};

#endif // Catalogue_H