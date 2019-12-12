#include <iostream>
#include "TrajetList.h"

using namespace std;

TrajetList::TrajetList() {
    Node *node = nullptr;
    this->head = node;
}

TrajetList::~TrajetList() {
    destroy(head);
}

void TrajetList::ajouterTete(Trajet *trajet) {
    Node *node = new Node();
    node->trajet = trajet;
    node->next = this->head;
    this->head = node;
}

void TrajetList::ajouterQueue(Trajet *trajet) {
    Node *node = new Node();
    node->trajet = trajet;
    if (this->head == nullptr) {
        this->head = node;
    } else {
        node->next = nullptr;
        Node *temp = this->head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

Trajet * TrajetList::premier() {
    return this->head->trajet;
}

Trajet * TrajetList::dernier() {
    Node *temp = this->head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp->trajet;
}

void TrajetList::afficher() {
    Node *current = this->head;
    while (current != nullptr) {
        current->trajet->afficher();
        if (current->next != nullptr) {
            cout << " - ";
        }
        current = current->next;
    }
}

void TrajetList::deleteFrom(const char * depart) {
    Node *current = this->head;
    Node *prev = nullptr;
    bool found = false;
    while (current != nullptr && !found) {
        if(strcmp(current->trajet->getVilleDepart(), depart) == 0) {
            found = true;
            if(prev != nullptr) {
                destroy(current);
                prev->next = nullptr;   
            } else {
                destroy(head);
                this->head = nullptr;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void TrajetList::destroy(Node *node) {
    while (node) {
        Node* old = node;
        node = node->next;
        delete(old->trajet);
        delete old;
    }
}