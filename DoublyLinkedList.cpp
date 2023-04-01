//
// Created by daniel on 01.04.23.
//

#include "DoublyLinkedList.h"
#include "Node.h"

DoublyLinkedList::DoublyLinkedList() {
    this -> head = nullptr;
    this -> tail = nullptr;
    this -> size = 0;
}

DoublyLinkedList::~DoublyLinkedList() = default;

void DoublyLinkedList::addBeginning(int value) {
    Node* node = new Node();
    node -> value = value;
    node -> next = head;
    if(head != nullptr) head -> prev = node;
    if(tail == nullptr) tail = node;
    head = node;
    node -> prev = nullptr;
    size++;
}

void DoublyLinkedList::addEnd(int value) {
    Node* node = new Node();
    node -> value = value;
    node -> next = nullptr;
    if(tail != nullptr) {
        tail -> next = node;
        node -> prev = tail;
    }
    if(tail == nullptr) head = node;
    tail = node;
    size++;
}

void DoublyLinkedList::addDesired(int value, int position) {
    if(position <= size && position >= 0){
        Node* node = new Node();
        node -> value = value;
        Node* searching = head;
        for(int i = 0; i < position - 1; i++){
            searching = searching -> next;
        }
        if(position == 0){
            if(head != nullptr){
                head -> prev = node;
                node -> next = head;
            } else tail = node;
            head = node;
        }
        else{
            node -> prev = searching;
            node -> next = searching -> next;
            if(position < size) searching -> next -> prev = node;
            else tail = node;
            searching -> next = node;
        }
        size++;
    }
}

void DoublyLinkedList::deleteBeginning() {
    if(size == 0) return;
    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
    }else{
        head = head -> next;
        delete head -> prev;
        head -> prev = nullptr;
    }
    size--;
}

void DoublyLinkedList::deleteEnd() {
    if(size == 0) return;
    if(head == tail){
        delete tail;
        head = nullptr;
        tail = nullptr;
    }else{
        tail = tail -> prev;
        delete tail -> next;
        tail -> next = nullptr;
    }
    size--;
}

void DoublyLinkedList::deleteDesired(int position) {
    if(position < size && position >= 0){
        Node* searching = head;
        for(int i = 0; i < position; i++){
            searching = searching -> next;
        }
        if(searching -> prev != nullptr) searching -> prev -> next = searching -> next;
        else head = searching -> next;
        if(searching -> next != nullptr) searching -> next -> prev = searching -> prev;
        else tail = searching -> prev;
        delete searching;
        size--;
    }
}

Node* DoublyLinkedList::search(int number) {
    Node* searching = head;
    for(int i = 0; i < size; i++){
        if(searching -> value == number) return searching;
        searching = searching -> next;
    }
    return nullptr;
}

void DoublyLinkedList::printList() {
    if(size > 0){
        Node* printing = head;
        while(printing != nullptr){
            cout << printing -> value << "|";
            printing = printing -> next;
        }
        cout << "\nHead: " << head -> value << "\nTail: "<< tail -> value << "\nSize: " << size;
    }
}