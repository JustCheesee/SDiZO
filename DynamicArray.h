//
// Created by Daniel Gaida on 31.03.23.
//

#ifndef SDIZO_DYNAMICARRAY_H
#define SDIZO_DYNAMICARRAY_H

class DynamicArray{
    private:
        int* array;
        int size;

    public:
        void addBeginning(int);
        void addEnd(int);
        void addDesired(int, int);
        void deleteBeginning();
        void deleteEnd();
        void deleteDesired(int);
        int search(int);
        void printArray();
        explicit DynamicArray(int);
        ~DynamicArray();
};

#endif //SDIZO_DYNAMICARRAY_H
