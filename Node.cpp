//
// Created by daniel on 01.04.23.
//

#include "Node.h"

Node::Node(){
    this -> next = nullptr;
    this -> prev = nullptr;
    this -> value = 0;
}
Node::~Node() = default;
