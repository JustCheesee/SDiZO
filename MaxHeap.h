//
// Created by daniel on 02.04.23.
//

#ifndef SDIZO_MAXHEAP_H
#define SDIZO_MAXHEAP_H

class MaxHeap{
    private:
        int size;
        int* heap;

    public:
        void addElement(int);
        void removeElement(int);
        int searchElement(int);
        void heapify(int);
        int getParent(int);
        int getLeft(int);
        int getRight(int);
        void printHeap();
        MaxHeap();
        ~MaxHeap();
};

#endif //SDIZO_MAXHEAP_H
