/*********************************************************
* Summary: This file contains defines all the methods declared in PriorityQueue.h 
* for Assignment 4: Implementation of Priority Queue using Binary Min-heap 
*
*  [ More high-level program descriptions come here ]
*
* Author: Yucheng Zhang
* Created: November 19, 2024
* Summary of Modifications [if applicable]:
*      19 Nov 2024 - Created file, defined member variables and function prototypes 
*                    for Priority Queue Class
*
*
********************************************************/

#include <iostream>
#include <vector>
#include <exception> 
#include "PriorityQueue.h"

using namespace std; 

// constructor that initializes heap with default capacity of 100
template <class T> 
PriorityQueue<T>::PriorityQueue(int capacity) : size(0), capacity(capacity){
    array.resize(capacity + 1);
}

// checks if the heap is empty. 
template <class T>
bool PriorityQueue<T>::isEmpty() const {
    return size == 0;
}

// inserts new element x into the priority queue, maintaining heap order 
template <class T>
void PriorityQueue<T>::insert(const T& x){
    // resizes the array if current size is equal to capacity
    if (size + 1 == capacity){
        array.resize(array.size() * 2 + 1);
    }

    // percolate up
    // increment size variable and assigns it to hole
    int hole = ++size;
    // loop while hole is not the root and x is less than the value of its parent node 
    for(; hole > 1 && x < array[hole/2]; hole /= 2){
        // percolates the parent node down to current hole (moves hole to parent position)
        array[hole] = array[hole/2];
    }
    array[hole] = x;
}

// removes the minimum element (root) from the heap and reorders the heap
template <class T>
void PriorityQueue<T>::deleteMin(){
    if(isEmpty()){
        throw underflow_error("Attempted to delete from an empty heap");
    }
    else{
        // replace the root with the last element in the heap, then decrease heap size by one (remove the last element)
        array[1] = array[size--];
        // call percolateDown() helper function at root to restore heap property
        percolateDown(1);
    }
}

template <class T>
void PriorityQueue<T>::percolateDown(int hole){
    int child;
    // save temporary value to be percolated down
    T tmp = array[hole];
    // loop while the node at hole has at least one child (checks left child) 
    // updates the value of hole as it percolates down
    for(; hole * 2 <= size; hole = child){
        // sets child to 2i 
        child = hole * 2;
        // checks if node at hole has a right child and if it is smaller than the left child
        if(child != size && array[child + 1] < array[child]){
            // if right is smaller, set child to the right child 
            child++;
        }
        // checks if the value at child index is smaller than the temporary value 
        if(array[child] < tmp){
            // replace the value at hole with the value at child (moves smaller value up)
            array[hole] = array[child];
        }
        else{
            break;
        }
    }
    // place tmp into the correct position in the heap
    array[hole] = tmp;
}


// print array representation queue
template <class T>
void PriorityQueue<T>::displayQueue() const{
    // check if queue is empty
    if (isEmpty()){
        cout << "The priority queue is empty." << endl;
        return;
    }
    else{
        // loop through array and print out values 
        for(int i=1; i <= size; i++){
            cout << array[i] << " ";
        }
    }
    cout << endl;
}

// to avoid linker errors with templates
template class PriorityQueue<int>;