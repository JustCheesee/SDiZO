#include "DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray(int s) {
    this -> array = new int[s];
    this -> size = s;
}

DynamicArray::~DynamicArray() = default;

void DynamicArray::addBeginning(int number) { //adds number at beginning of array
    int* new_array = new int[size + 1];
    for(int i = 0; i < size; i++){
        new_array[i + 1] = array[i];
    }
    new_array[0] = number;
    delete [] array;
    array = new_array;
    size++;
}

void DynamicArray::addEnd(int number) {     //adds number at end of array
    int* new_array = new int[size + 1];
    for(int i = 0; i < size; i++){
        new_array[i] = array[i];
    }
    new_array[size] = number;
    delete [] array;
    array = new_array;
    size++;
}

void DynamicArray::addDesired(int number, int position) {   //adds number at desired position in array
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

void DynamicArray::deleteBeginning() {  //deletes number at beginning of array
    if(size == 0) return;
    int* new_array = new int[size - 1];
    for(int i = 0; i < size - 1; i++){
        new_array[i] = array[i + 1];
    }
    delete [] array;
    array = new_array;
    size--;
}

void DynamicArray::deleteEnd() {    //deletes number at end of array
    if(size == 0) return;
    int* new_array = new int[size - 1];
    for(int i = 0; i < size - 1; i++){
        new_array[i] = array[i];
    }
    delete [] array;
    array = new_array;
    size--;
}

void DynamicArray::deleteDesired(int position) {    //deletes number at desired position in array
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

int DynamicArray::search(int number) {  //searches array for given number and returns its position if it exists
    for(int i = 0; i < size; i++){
        if(array[i] == number) return i;
    }
    return -1;
}

void DynamicArray::printArray() {       //prints array in console
    for(int i = 0; i < size; i++){
        cout << array[i] << "|";
    }
    cout << "\nSize of Array: " << size;
}