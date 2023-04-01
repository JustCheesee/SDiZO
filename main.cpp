//
// Created by Daniel Gaida on 31.03.23.
//

#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include "DoublyLinkedList.h"
#include "DoublyLinkedList.cpp"
#include "Node.cpp"

using namespace std;

int main(){
//    DynamicArray a1(0);
//    a1.addBeginning(1);
//    a1.addBeginning(2);
//    a1.addEnd(3);
//    a1.addEnd(4);
//    a1.addBeginning(5);
//    a1.addEnd(6);
//    a1.addDesired(7, 5);
//    a1.deleteBeginning();
//    a1.addBeginning(8);
//    a1.deleteEnd();
//    a1.deleteEnd();
//    a1.deleteDesired(2);
//    int position = a1.search(6);
//    cout << position;
//    a1.printArray();

    DoublyLinkedList d1;
//    d1.addBeginning(2);
//    d1.addBeginning(3);
//    d1.addEnd(4);
//    d1.addEnd(5);
//    d1.addBeginning(6);
//    d1.addDesired(7, 0);
//    d1.addBeginning(8);
    d1.addDesired(9, 0);
    d1.printList();

    return 0;
}