//
// Created by Daniel Gaida on 31.03.23.
//

#include "DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray(int s) {
    this -> array = new int[s];
    this -> size = s;
}

DynamicArray::~DynamicArray() = default;

void DynamicArray::addBeginning(int number) {
    int* new_array = new int[size + 1];
    for(int i = 0; i < size; i++){
        new_array[i + 1] = array[i];
    }
    new_array[0] = number;
    delete [] array;
    array = new_array;
    size++;
}

void DynamicArray::addEnd(int number) {
    int* new_array = new int[size + 1];
    for(int i = 0; i < size; i++){
        new_array[i] = array[i];
    }
    new_array[size] = number;
    delete [] array;
    array = new_array;
    size++;
}

void DynamicArray::addDesired(int number, int position) {
    if(position <= size && position >= 0){
        int* new_array = new int[size + 1];
        for(int i = 0; i < size; i++){
            if (i < position) new_array[i] = array[i];
            else new_array[i + 1] = array[i];
        }
        new_array[position] = number;
        delete [] array;
        array = new_array;
        size++;
    }
}

void DynamicArray::deleteBeginning() {
    if(size == 0) return;
    int* new_array = new int[size - 1];
    for(int i = 0; i < size - 1; i++){
        new_array[i] = array[i + 1];
    }
    delete [] array;
    array = new_array;
    size--;
}

void DynamicArray::deleteEnd() {
    if(size == 0) return;
    int* new_array = new int[size - 1];
    for(int i = 0; i < size - 1; i++){
        new_array[i] = array[i];
    }
    delete [] array;
    array = new_array;
    size--;
}

void DynamicArray::deleteDesired(int position) {
    if(position <= size && size != 0 && position >= 0){
        int* new_array = new int[size - 1];
        for(int i = 0; i < size - 1; i++){
            if (i < position) new_array[i] = array[i];
            else new_array[i] = array[i + 1];
        }
        delete [] array;
        array = new_array;
        size--;
    }
}

int DynamicArray::search(int number) {
    for(int i = 0; i < size; i++){
        if(array[i] == number) return i;
    }
    return -1;
}

void DynamicArray::printArray() {
    for(int i = 0; i < size; i++){
        cout << array[i] << "|";
    }
    cout << "\nSize of Array: " << size;
}