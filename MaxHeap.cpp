//
// Created by daniel on 02.04.23.
//

#include "MaxHeap.h"
#include <iostream>
#include <math.h>
using namespace std;

MaxHeap::MaxHeap() {
    this -> size = 0;
    this -> heap = nullptr;
}

MaxHeap::~MaxHeap() = default;

int MaxHeap::getParent(int i) {
    return (i - 1)/2;
}

int MaxHeap::getLeft(int i) {
    return 2*i + 1;
}

int MaxHeap::getRight(int i) {
    return 2*i + 2;
}

void MaxHeap::addElement(int value) {
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

void MaxHeap::removeElement(int position) {
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

void MaxHeap::heapify(int i) {
    int left = getLeft(i);
    int right = getRight(i);
    int largest;
    if(left < size && heap[left] > heap[i]) largest = left;
    else largest = i;
    if(right < size && heap[right] > heap[largest]) largest = right;
    if(largest != i){
        int tmp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = tmp;
        heapify(largest);
    }
}

int MaxHeap::searchElement(int value) {
    for(int i = 0; i < size; i++){
        if(heap[i] == value) return i;
    }
    return -1;
}

void MaxHeap::printHeap() {
    int current = 0;
    int height = floor(log2(size));
    for(int i = 0; i <= height; i++){
        cout << "---" << heap[current];
        current = getRight(current);
    }
    current = getParent(current);
    
}