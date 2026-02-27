#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "./include/doctest.h" 
#include "linked_list.h"

using namespace std;

TEST_CASE("Testing linked list constructor - Empty") {
    LinkedList myLL;
    CHECK(myLL.getFirstElement() == nullptr);
    CHECK(myLL.sizeOfList() == 0);
}

TEST_CASE("Testing linked list constructor - 1 node") {
    LinkedList myLL;
    myLL.insertAtFront(4);

    CHECK(myLL.getFirstElement()->data == 4);
    CHECK(myLL.getFirstElement()->next == myLL.getFirstElement());
    CHECK(myLL.sizeOfList() == 1);
}

TEST_CASE("Testing insertions (at front and at back)"){
    LinkedList myLL;

    for (int i=2; i<10; i++){
        myLL.insertAtEnd(i);
    }

    // cout << myLL << endl;

    myLL.insertAtFront(1);
    myLL.insertAtEnd(10);

    // cout << myLL << endl;

    CHECK(myLL.getFirstElement()->data == 1);
    CHECK(myLL.getFirstElement()->next->data == 2);
    
    CHECK(myLL.getLastElement()->data == 10);
    CHECK(myLL.getLastElement()->next->data == 10);
}

TEST_CASE("Delete head node") {
    LinkedList myLL;
    myLL.insertAtEnd(1);
    myLL.insertAtEnd(2);
    myLL.insertAtEnd(3);

    myLL.deleteNode(0);
    CHECK(myLL.getFirstElement()->data == 2);
    CHECK(myLL.sizeOfList() == 2);
}

TEST_CASE("Delete last node") {
    LinkedList myLL;
    myLL.insertAtEnd(1);
    myLL.insertAtEnd(2);
    myLL.insertAtEnd(3);

    myLL.deleteNode(2);
    CHECK(myLL.sizeOfList() == 2);
    CHECK(myLL.getLastElement()->data == 2);
    CHECK(myLL.getLastElement()->next == myLL.getLastElement());
}

TEST_CASE("Delete only node") {
    LinkedList myLL;
    myLL.insertAtEnd(5);

    myLL.deleteNode(0);
    CHECK(myLL.sizeOfList() == 0);
    CHECK(myLL.getFirstElement() == nullptr);
}

TEST_CASE("Non-negative prefix sum - all positive") {
    LinkedList myLL;
    myLL.insertAtEnd(1);
    myLL.insertAtEnd(1);
    myLL.insertAtEnd(1);

    CHECK(myLL.non_neg_prefix_sum() == true);
    CHECK(myLL.non_pos_prefix_sum() == false);
}

TEST_CASE("Non-positive prefix sum - all negative") {
    LinkedList myLL;
    myLL.insertAtEnd(-1);
    myLL.insertAtEnd(-1);
    myLL.insertAtEnd(-1);

    CHECK(myLL.non_pos_prefix_sum() == true);
    CHECK(myLL.non_neg_prefix_sum() == false);
}

TEST_CASE("Pointer jumping - all point to last") {
    LinkedList myLL;
    myLL.insertAtEnd(1);
    myLL.insertAtEnd(2);
    myLL.insertAtEnd(3);
    myLL.insertAtEnd(4);

    Node * last = myLL.getLastElement();
    myLL.pointerJumping();

    CHECK(last->next == last);
    CHECK(myLL.getFirstElement()->next == last);
}
