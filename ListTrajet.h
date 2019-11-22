#include "Trajet.h"
#include "Node.h"

class ListTrajet {
    protected:
        Node * head;
    public:
        ListTrajet();
        void push(Trajet * trajet);
        void print();
};