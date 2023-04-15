#include "MaxHeap.h"
#include <iostream>
#include <math.h>
using namespace std;

MaxHeap::MaxHeap() {            //heap represented as array
    this -> size = 0;
    this -> heap = nullptr;
}

MaxHeap::~MaxHeap() = default;

int MaxHeap::getParent(int i) {     //helping functions for getting parent, left and right child at given position
    return (i - 1)/2;
}

int MaxHeap::getLeft(int i) {
    return 2*i + 1;
}

int MaxHeap::getRight(int i) {
    return 2*i + 2;
}

void MaxHeap::addElement(int value) {   //adds element to heap
    int* new_heap = new int[size + 1];
    for(int i = 0; i < size; i++){
        new_heap[i] = heap[i];
    }
    delete [] heap;
    heap = new_heap;
    int i = size;
    while(i > 0 && heap[getParent(i)] < value){
        heap[i] = heap[getParent(i)];
        i = getParent(i);
    }
    heap[i] = value;
    size++;
}

void MaxHeap::removeElement(int value) { //removes element from heap at given position
    int position = searchElement(value);
    if(position < size && position >= 0){
        int * new_heap = new int[size - 1];
        heap[position] = heap[size - 1];
        if(size > 1){
            for(int i = 0; i < size; i++){
                new_heap[i] = heap[i];
            }
        }
        delete [] heap;
        heap = new_heap;
        heapify(position);
        size--;
    }
}

void MaxHeap::heapify(int i) {      //heapify function to restore heap
    int left = getLeft(i);
    int right = getRight(i);
    int largest;
    if(left < size && heap[left] > heap[i]) largest = left;     //check which number is larger: i, left child of i or right child of i
    else largest = i;
    if(right < size && heap[right] > heap[largest]) largest = right;
    if(largest != i){           //if i is not the largest swap largest for i and again call heapify at largest
        int tmp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = tmp;
        heapify(largest);
    }
}

int MaxHeap::searchElement(int value) { //searches for element with given value and returns it index in array
    for(int i = 0; i < size; i++){
        if(heap[i] == value) return i;
    }
    return -1;
}

void MaxHeap::printHeap(int i, string indent, bool last) {     //prints heap in console
    if (i < size) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }
        cout << heap[i] << endl;
        printHeap(getLeft(i) ,indent, false);
        printHeap(getRight(i), indent, true);
    }
}