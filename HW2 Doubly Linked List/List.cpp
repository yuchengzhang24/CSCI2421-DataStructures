//
//  List.cpp
//  DoublyLinkedList
//
//  Created by Madhuri Debnath on 9/24/20.
//

#include<iostream>
#include "List.h"
using namespace std;

void List::insert(int value){
  //Creates a new node with data of value and points the next ptr to tailPtr because we know it's inserted at the end of the list.
  Node* insertedNode = new Node(value);
  insertedNode -> setNextPtr(tailPtr);
  
  //Checks if the next of headPtr is NULL (the list is empty)
  if (headPtr -> getNextPtr() == NULL){
    //Sets the next of headPtr to the inserted node and points the prev of inserted node to headPtr. 
    headPtr -> setNextPtr(insertedNode);
    insertedNode -> setPrevPtr(headPtr);
  }

  //Else, insert the pointer at the end (prev of TailPtr).
  else {
    Node* prevNode = tailPtr->getPrevPtr();
    prevNode->setNextPtr(insertedNode);
    insertedNode->setPrevPtr(prevNode);
    insertedNode->setNextPtr(tailPtr);
  }

  //Sets the prev of tailPtr to point to inserted node. 
  tailPtr -> setPrevPtr(insertedNode);
}

void List::insertAtIndex(int data, int index)
{}
void List::deleteAtIndex(int index)
{}
void List::readItem(int index){}

void List::reverseList(){}

void List::printForward(){
  //Creates a current node pointer that points to the next of head pointer.
  Node *currentNode = headPtr -> getNextPtr();

  //Creates a while loop that traverses through the list until the next of current node points to NULL (end of list is reached).
  while (currentNode != NULL){
    //Gets the data at current node and prints it out, then sets current node to the next of current. 
    cout << currentNode -> getData() << ", ";
    currentNode = currentNode -> getNextPtr();
  }
  cout << endl;
}

void List::printBackward()
{}
