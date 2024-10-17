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
  // Create a new node with the given value
  Node* insertedNode = new Node(value);
  
  // Set the next pointer of the new node to the tail pointer
  insertedNode->setNextPtr(tailPtr);
  
  // Check if the list is empty
  if (headPtr->getNextPtr() == NULL){
    // Set the next pointer of the head to the new node
    headPtr->setNextPtr(insertedNode);
    // Set the previous pointer of the new node to the head
    insertedNode->setPrevPtr(headPtr);
  }
  else {
    // If the list is not empty, find the node before the tail
    Node* prevNode = tailPtr->getPrevPtr();
    
    // Set the next pointer of the previous node to the new node
    prevNode->setNextPtr(insertedNode);
    // Set the previous pointer of the new node to the previous node
    insertedNode->setPrevPtr(prevNode);
    // Set the next pointer of the new node to the tail
    insertedNode->setNextPtr(tailPtr);
  }
  
  // Set the previous pointer of the tail to the new node
  tailPtr->setPrevPtr(insertedNode);
}


void List::insertAtIndex(int data, int index){
  // Check if the list is empty
  if (headPtr->getNextPtr() == NULL) {
    // If empty, insert the data at the beginning
    insert(data);
    return;
  }

  // Initialize pointers to traverse the list
  Node *currentNode = headPtr -> getNextPtr();
  Node *prevNode = headPtr;
  int i = 0;

  // Traverse the list until the index
  while (currentNode != NULL && i < index){
    prevNode = currentNode;
    currentNode = currentNode -> getNextPtr();
    i++;
  }

  if (currentNode != NULL && i == index) {
    // Create a new node with the given data
    Node* insertedNode = new Node(data);
    // Set the next pointer of the new node to the current node
    insertedNode -> setNextPtr(currentNode);
    // Set the previous pointer of the new node to the previous node
    insertedNode -> setPrevPtr(prevNode);
    // Set the previous pointer of the current node to the new node
    currentNode -> setPrevPtr(insertedNode);
    // Set the next pointer of the previous node to the new node
    prevNode -> setNextPtr(insertedNode);
  }
}


void List::deleteAtIndex(int index){
  // Check if the list is empty
  if (headPtr->getNextPtr() == NULL){
    cout << "List is empty." << endl;
    return;
  }

  // Initialize pointers to traverse the list
  Node *currentNode = headPtr -> getNextPtr();
  Node *prevNode = headPtr;
  int i = 0;

  // Traverse the list until the index
  while (currentNode != NULL && i < index){
    prevNode = currentNode;
    currentNode = currentNode -> getNextPtr();
    i++;
  }

  if (currentNode != NULL && i == index){
    // Check that the current node is not the last node
    if (currentNode->getNextPtr() != NULL) {
      // Set the previous pointer of the next node to the previous node
      currentNode -> getNextPtr() -> setPrevPtr(prevNode);
    }
    // Set the next pointer of the previous node to the next node
    prevNode -> setNextPtr(currentNode -> getNextPtr());
    // Disconnect the current node from the list
    currentNode -> setNextPtr(NULL);
    currentNode -> setPrevPtr(NULL);
    // Delete the current node
    delete currentNode;
    currentNode = NULL;
  }
}


void List::readItem(int index){
  // Check if the list is empty
  if (headPtr->getNextPtr() == NULL){
    cout << "List is empty." << endl;
    return;
  }

  // Initialize a pointer to traverse the list
  Node *currentNode = headPtr -> getNextPtr();
  int i = 0;

  // Traverse the list until the specified index
  while (currentNode != NULL && i < index){
    currentNode = currentNode -> getNextPtr();
    i++;
  }

  // Check if the index is out of bounds
  if (currentNode -> getNextPtr() == NULL) {
    cout << "Index out of bounds." << endl;
    return;
  }

  // If the current index matches the specified index, print the data
  else if (i == index){
    cout << currentNode -> getData() << endl;
  }
}


void List::reverseList(){
  // Check if the list is empty or has only one element
  if (headPtr == NULL || headPtr -> getNextPtr() == NULL){
    cout << "List is empty." << endl;
    return;
  }

  // Initialize pointers to traverse and reverse the list
  Node *currentNode = headPtr;
  Node *nextNode = NULL;
  Node *prevNode = NULL;

  // Traverse the list and reverse the pointers
  while(currentNode != NULL){
    // Set the next node
    nextNode = currentNode -> getNextPtr();
    // Reverse the previous pointer to point to the next node
    currentNode -> setPrevPtr(nextNode);
    // Reverse the next pointer to point to the previous node
    currentNode -> setNextPtr(prevNode);
    // Traverse to the next node
    prevNode = currentNode;
    currentNode = nextNode;
  }

  // Update the head and tail pointers
  tailPtr = headPtr;
  headPtr = prevNode;
  // Point tail to NULL
  tailPtr -> setNextPtr(NULL);
}


void List::printForward(){
  // Check if the list is empty
  if (headPtr -> getNextPtr() == NULL){
    cout << "List is empty." << endl;
    return;
  }
  
  // Start at the node after the headPtr
  Node *currentNode = headPtr -> getNextPtr();

  // Traverse the list until the node before the tail pointer
  while (currentNode != tailPtr){
    // Print the data of the current node
    cout << currentNode -> getData() << " ";
    // Move to the next node
    currentNode = currentNode -> getNextPtr();
  }
  cout << endl;
}


void List::printBackward(){
  // Check if the list is empty
  if (headPtr -> getNextPtr() == NULL){
    cout << "List is empty." << endl;
    return;
  }

  // Start from the node before the tail pointer
  Node *currentNode = tailPtr -> getPrevPtr();

  // Traverse backwards until the node before the head pointer
  while (currentNode != headPtr){
    // Print the data of the current node
    cout << currentNode -> getData() << " ";
    // Move to the previous node
    currentNode = currentNode -> getPrevPtr();
  }
  cout << endl;
}
