//
// Created by daniel on 01.04.23.
//

#ifndef SDIZO_DOUBLYLINKEDLIST_H
#define SDIZO_DOUBLYLINKEDLIST_H
#include "Node.h"

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
        int size;

    public:
        void addBeginning(int);
        void addEnd(int);
        void addDesired(int, int);
        void deleteBeginning();
        void deleteEnd();
        void deleteDesired(int);
        int search(int);
        void printList();
        DoublyLinkedList();
        ~DoublyLinkedList();
};

#endif //SDIZO_DOUBLYLINKEDLIST_H
