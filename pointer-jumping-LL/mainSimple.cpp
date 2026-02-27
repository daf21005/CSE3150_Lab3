#include <iostream>
#include "linked_list.h"

using namespace std;

int main(){
    LinkedList myLinkedList;

    // cout << myLinkedList.getFirstElement() << endl;

    // insert 0,1,2,3,4 at the front of the linked list
    for (int i=0; i<5; i++){
        myLinkedList.insertAtFront(i);
    }
    cout << "Initial linked list:" << endl;
    cout << myLinkedList << endl;

    // insert 5 at the end
    cout << "Adding 5 to the end: " << endl;
    myLinkedList.insertAtEnd(5);
    cout << myLinkedList << endl;

    // deleting the 3rd node from the linked list (in this case will be 2)
    cout << "Removing the 3rd node: " << endl;
    myLinkedList.deleteNode(2);
    cout << myLinkedList << endl;

    // cout << "The first element of the list: " << endl;
    // cout << myLinkedList.getFirstElement() << endl;

    // Linked List that contains +1 and -1
    cout << "New linked list with +1 and -1:" << endl;
    LinkedList onesList;
    for (int i=0; i<5; i++){
        if (i % 2 == 0) {
            onesList.insertAtEnd(1);
        } else {
            onesList.insertAtEnd(-1);
        }
    }

    cout << onesList << endl;


    // checks for prefix sum
    if(onesList.non_neg_prefix_sum()){
        cout << "The linked list forms a positice prefix sum." << endl;
    }else if(onesList.non_pos_prefix_sum()){
        cout << "The linked list forms a negative prefix sum." << endl;
    } else {
        cout << "The linked list is balanced." << endl;
    }

    onesList.insertAtEnd(-1);

    cout << onesList << endl;

    if(onesList.non_neg_prefix_sum()){
        cout << "The linked list forms a positice prefix sum." << endl;
    }else if(onesList.non_pos_prefix_sum()){
        cout << "The linked list forms a negative prefix sum." << endl;
    }else {
        cout << "The linked list is balanced." << endl;
    }

    onesList.insertAtFront(-1);

    cout << onesList << endl;

    if(onesList.non_neg_prefix_sum()){
        cout << "The linked list forms a positice prefix sum." << endl;
    }else if(onesList.non_pos_prefix_sum()){
        cout << "The linked list forms a negative prefix sum." << endl;
    }else {
        cout << "The linked list is balanced." << endl;
    }

    cout << onesList.sizeOfList() << endl;

    onesList.pointerJumping();
    onesList.printNodeAddresses();

    return 0;
}

// commands ran: g++ mainSimple.cpp - ./a.out - valgrind ./a.out - 
