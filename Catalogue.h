#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include "TrajetList.h"

class Catalogue : public TrajetList {

    private:
        typedef struct StringList{
            const char** list;
            int index;
        }StringList;

    public:
        void ajouterTrajetSimple (  );
        void ajouterTrajetCompose (  );
        void listerTrajets (  );
        void afficher (  );
        TrajetList * findRoute (const char * depart,const char * arrive );
        TrajetList * findRouteComp (const char * depart,const char * arrive );
        void dfs( const char * depart, StringList* visited );
};

#endif // Catalogue_H
