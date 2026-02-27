#include <iostream>
#include <vector>
#include <cstdlib> // used for abs
#include "linked_list.h"

using namespace std;

// constructor part:

// note to self: this is an Member Initializer Lists different from a default constructor
LinkedList::LinkedList() : root(nullptr) {}

// destructor
LinkedList::~LinkedList() {
    if (!root) return; // if the list is empty (edge case)

    // the vector nodeAddresses has addresses that must be deleted
    if(!nodeAddresses.empty()){
        for(auto address : nodeAddresses){
            delete static_cast<Node *>(address);
        }
    } else {
        // if we didnt call pointer jumping the nodes are still linked 
        Node * current = root;
        // iterate till the last node
        while (current != current->next) {
            Node * next = current->next;
            delete current;
            current = next;
        }
        // handles the last node and root
        delete current;
    }
    root = nullptr;
}

// copy constructor
LinkedList::LinkedList(const LinkedList & oldLL){
    // if the linked list is empty
    if (oldLL.root == nullptr){
        root = nullptr;
        return;
    }

    // copy first node
    root = new Node(oldLL.root->data);

    Node * currentOld = oldLL.root;
    Node * currentNew = root;

    while(currentOld != currentOld->next){
        currentOld = currentOld->next;
        Node * newNode = new Node(currentOld->data);
        currentNew->next = newNode;
        currentNew = newNode;
    }
    currentNew->next = currentNew;

}

// functions
// adding a node at the beggining
void LinkedList::insertAtFront(int value){
    Node * newNode = new Node(value);

    // if linked list is empty 
    if(root == nullptr){
        newNode->next = newNode;
        root = newNode;
    }else{
        // if theirs already nodes
        newNode->next = root;
        root = newNode;
    }
}

// adding a node at the end
void LinkedList::insertAtEnd(int value){
    Node * newNode = new Node(value);

    // if linked list is empty
    if(!root){
        root = newNode;
        return;
    }

    Node * current = root;

    while(current != current->next){
        current = current->next;
    }
    // iterate one more and then make the new node point to itself
    current->next = newNode;
    newNode->next = newNode;
}

void LinkedList::deleteNode(int nodeNum){
    // if the linked list is empty
    if (!root) return;

    // deleting the head (first element)
    if (nodeNum == 0){
        Node* temp = root;
        // only one node (it points to itself)
        if(root == root->next){
            root = nullptr;
        }else{
            // list contains more than one
            root = root->next;
        }

        // now that the node lost its link we must delete it (preventing memory leak)
        delete temp;
        return;
    }

    Node* current = root->next;
    Node* prev = root;

    // update the pointers as we iterate through the list and make sure we don't dont go over the length of the list
    int i = 1;
    for (; i < nodeNum && current != current->next; i++){
        current = current->next;
        prev = prev->next;
    }

    // this is if the node number is bigger than the length of the list
    if (i != nodeNum){
        cout << "Must enter a valid node number" << endl;
        return;
    }

    // deleting the ith node
    if(current == current->next){
        prev->next = prev;
    }else{
        prev->next = current->next;
    }
    delete current;
}


// positive prefix sum
bool LinkedList::non_neg_prefix_sum(){
    // if the linked list is empty
    if (!root) return false;

    int sum = 0;
    Node * current = root;

    // this will iterate till the last node
    while(current != current->next){
        // checks if the linked list contains +1s and -1s
        if(abs(current->data) != 1){
            return false;
        }

        sum += current->data;
        if(sum<0){
            return false;
        }
        current = current->next;
    }
    // we need to include the last node
    sum += current->data;

    if(sum<=0) return false;
    return true;
}

// negative prefix sum
bool LinkedList::non_pos_prefix_sum(){
    // if the linked list is empty
    if (!root) return false;

    int sum = 0;
    Node * current = root;

    // this will iterate till the last node
    while(current != current->next){
        // checks if the linked list contains +1s and -1s
        if(abs(current->data) != 1){
            return false;
        }

        sum += current->data;
        if(sum>0){
            return false;
        }
        current = current->next;
    }
    // we need to include the last node
    sum += current->data;

    if(sum>=0) return false;
    return true;
}

// other functions used for unit testing
Node * LinkedList::getFirstElement(){
    return root;
}

Node * LinkedList::getLastElement(){
    if (!root) return nullptr;

    Node * current = root;
    while(current != current->next){
        current = current->next;
    }

    return current;
}

void LinkedList::traverseList(){
    Node * current = root;

    while(current->next != current){
        cout << current->data << " ";
        current = current->next;
    }

    cout << current->data << endl;
}

int LinkedList::sizeOfList(){
    if(!root) return 0;

    Node * current = root;

    int length = 0;

    while(current->next != current){
        length += 1;
        current = current->next;
    }
    // last node needs to be included
    length += 1;

    return length;
}

void LinkedList::printNodeAddresses(){
    for (auto address : nodeAddresses){
        cout << address << endl;
    }
}



// pointer jumping algorithm:
void LinkedList::copyAllNodeAddresses(){
    nodeAddresses.clear();
    // if the list is empty
    if (!root) return;

    Node * current = root;

    while(current != current->next){
        nodeAddresses.push_back(current);
        current = current->next;
    }

    nodeAddresses.push_back(current);
    // return;
}

void LinkedList::pointerJumping(){
    if(!root) return;

    copyAllNodeAddresses();


    bool changed = true;
    while(changed){
        changed = false;

        // iterate through the list by their addresses
        for (auto address : nodeAddresses){
            Node * node = static_cast<Node *>(address);

            // make sure we dont modify the last node
            if(node->next != node->next->next){
                node->next = node->next->next;
                changed = true;
            }
        }
    }

}

// OSTREAMS
ostream & operator<<(ostream & os, const Node & node) {
    os << node.data;
    return os;
}

ostream & operator<<(ostream & os, const LinkedList & linkedlist) {
    if (!linkedlist.root) return os;

    Node * traversal = linkedlist.root;

    while (traversal != traversal->next) {
        os << *traversal << " ";
        traversal = traversal->next;
    }

    os << *traversal;
    return os;
}