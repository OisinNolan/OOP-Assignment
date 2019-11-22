#include "Trajet.h"
#include "ListTrajet.h"

class Catalog : public ListTrajet {
    public:
        Trajet * findRoute(char * depart, char * arrive);
};