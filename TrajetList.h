#if ! defined ( TRAJETLIST_H )
#define TRAJETLIST_H

#include "Trajet.h"

class TrajetList {
    protected:
        struct Node {
            Trajet *trajet;
            Node *next;
        };
        Node *head;
    public:
        TrajetList();
        virtual ~TrajetList();
        void ajouterTete(Trajet *trajet);
        void ajouterQueue(Trajet *trajet);
        Trajet * premier();
        Trajet * dernier();
        void afficher();
        void deleteFrom(const char * depart);
        void destroy(Node *node);
};

#endif // TrajetList_H