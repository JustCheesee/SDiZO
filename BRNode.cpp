#include "BRNode.h"

BRNode::BRNode() {
    this -> left = nullptr;
    this -> right = nullptr;
    this -> parent = nullptr;
    this -> color = 0;
    this -> key = 0;
}
BRNode::~BRNode() = default;

