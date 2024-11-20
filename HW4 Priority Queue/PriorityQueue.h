/*********************************************************
* Summary: This file contains class declaration for Priority Queue Class
for Assignment 4: Implementation of Priority Queue using Binary Min-heap 
*
*  [ More high-level program descriptions come here ]
*
* Author: Yucheng Zhang
* Created: November 19, 2024
* Summary of Modifications [if applicable]:
*      19 Nov 2024 - Created file, declared class, member variables and function prototypes 
*
*
********************************************************/

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include <exception> 

using namespace std; 

// template for representing Priority Queue
template <class T>
class PriorityQueue{
    // private data/member variables 
    private:
        vector<T> array;
        int size;
        int capacity;
        void percolateDown(int hole);
    public: 
        // constructor that initializes the heap with a default capacity of 100
        PriorityQueue(int capacity = 100);
        // checks if the heap is empty. 
        bool isEmpty() const; 
        // inserts new element x into the heap 
        void insert(const T& x);
        // removes the minumum element from heap. In binary min-heap, this is the root. 
        void deleteMin();
        // print queue
        void displayQueue() const;
};


#endif // PRIORITYQUEUE_H