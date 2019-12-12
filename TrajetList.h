#if ! defined ( TRAJETLIST_H )
#define TRAJETLIST_H

#include "Trajet.h"

class Node {
    public:
        Trajet *trajet;
        Node *next;
};

class TrajetList {
    protected:
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