#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
#include <vector>
#include <cstdlib> // used for abs
#include "Node.h"

using namespace std;

class LinkedList {
    // this will have access to root (declarition)
    friend ostream & operator<<(ostream & os, const LinkedList & linkedlist);

    // pointer root to a node
    Node * root;
    vector<void *> nodeAddresses; // use to store the addresses of the nodes (right before the pointer jumping)

    public:
        // constructors:
        LinkedList();
        LinkedList(const LinkedList & other);
        ~LinkedList();

        // methods:
        // insertions
        void insertAtFront(int value);
        void insertAtEnd(int value);

        // deletion
        void deleteNode(int nodeNum);

        // prefix sums
        bool non_neg_prefix_sum();
        bool non_pos_prefix_sum();

        // pointer jumping
        void copyAllNodeAddresses();
        void pointerJumping();

        // other
        Node * getFirstElement();
        Node * getLastElement();
        
        void traverseList();
        int sizeOfList();
        void printNodeAddresses();
        
        
};

ostream & operator<<(ostream & os, const Node & node);
ostream & operator<<(ostream & os, const LinkedList & linkedlist);


#endif