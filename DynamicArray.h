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
        DynamicArray();
        ~DynamicArray();
};

#endif //SDIZO_DYNAMICARRAY_H
