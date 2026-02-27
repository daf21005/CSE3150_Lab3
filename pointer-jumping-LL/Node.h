#ifndef _NODE_H
#define _NODE_H

#include <iostream>

using namespace std;

struct Node{
    int data;
    // pointer next to a node
    Node* next;

    // member initializer list (setting data to 0 and next to nullptr)
    Node() : data(0), next(nullptr) {}
    // custom constructor
    // key term this to point to itself
    Node(int _data) : data(_data), next(this) {}

    // after more research we could combine the two lines to this:
    // Node(int _data = 0) : data(_data), next(nullptr) {}
};

#endif