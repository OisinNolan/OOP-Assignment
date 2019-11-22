#include "ListTrajet.h"
#include <iostream>

using namespace std;

ListTrajet::ListTrajet() {
    Node * node = nullptr;
    this->head = node;
}

void ListTrajet::push(Trajet * trajet) {
    Node * node = new Node();
    node->trajet = trajet;
    node->next = this->head;
    this->head = node;
}

void ListTrajet::print() {
    Node * current = this->head;
    while(current != nullptr) {
        current->trajet->afficher();
        current = current->next;
    }
}