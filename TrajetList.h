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