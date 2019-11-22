#include "Catalog.h"
#include "Trajet.h"
#include <cstring>

Trajet * Catalog::findRoute(char * depart, char * arrive) {
    Node * current = this->head;
    while(current != 0) {
        if(strcmp(current->trajet->depart, depart) == 0
            &&  strcmp(current->trajet->arrive, arrive) == 0) {
                return current->trajet;
        }
    }
    return 0;
}
