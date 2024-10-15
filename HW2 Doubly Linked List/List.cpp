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
