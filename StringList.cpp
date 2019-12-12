#include "StringList.h"
#include <cstring>
#include <iostream>

StringList::StringList() {
    StringNode * node = nullptr;
    this->head = node;
}

void StringList::add(const char * s) {
    StringNode * node = new StringNode();
    node->str = s;
    node->next = this->head;
    this->head = node;
}

bool StringList::contains(const char * s) {
    StringNode * runner = this->head;
    while(runner != nullptr) {
        if(strcmp(runner->str, s) == 0) {
            return true;
        }
        runner = runner->next;
    }
    return false;
}

StringList::~StringList() {
    while (head) {
        StringNode* old = head;
        head = head->next;
        //delete(old->str);
        delete old;
    }
}