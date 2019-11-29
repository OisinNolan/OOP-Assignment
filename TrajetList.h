#if ! defined ( TRAJETLIST_H )
#define TRAJETLIST_H

#include "Trajet.h"
#include "Node.h"

class TrajetList {
    protected:
        Node *head;
    public:
        TrajetList();
        void ajouterTete(Trajet *trajet);
        void ajouterQueue(Trajet *trajet);
        Trajet * premier();
        Trajet * dernier();
        void afficher();
};

#endif // TrajetList_H