#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include "TrajetList.h"
#include "TrajetCompose.h"
#include "StringList.h"

class Catalogue : public TrajetList {
    public:
        void ajouterTrajetSimple (  );
        void ajouterTrajetCompose (  );
        void listerTrajets (  );
        void afficher (  );
        TrajetList * findRoute (const char * depart,const char * arrive );
        TrajetList * findRouteComp (const char * depart,const char * arrive );
        void dfs( const char * current, const char * search, StringList * visited, TrajetList * results, TrajetList * path);
};

#endif // Catalogue_H
