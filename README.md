# CSE3150 Lab3
In this lab assignment we are implementing a linked list with C++.  

We are adding the basic properties of a linked list with some addition implementations:  
- Adding a data node at the beginning or at the end of the list
- A delete method that deletes the ith node in the linked list
- Last node will point to it self
- A pointer jumping algorithm where all nodes points to the last node (a method)
- An array that will hold the addresses the nodes before we perform the pointer jumping algortihm
- Checks the data if the linked list forms a positive or negative prefix sum (linked list must contain +1s or -1s)

After calling the pointer jumping function, all other function will become absolete and unable to print the linked list afterwards. 


## Compile and Run the main program:
```
g++ linked_list.cpp mainSimple.cpp -o mainProgram
./mainProgram
```

## Compile and Run unit test:
```
g++ linked_list.cpp testLinkedList.cpp -o testProgram
./testProgram
```