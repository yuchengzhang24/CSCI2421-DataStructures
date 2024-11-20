/*******************************************************
Name       :  Yucheng Zhang
Class      :  CSCI 2421 Section 001
Assignment :  Assignment 4: Implementation of Priority Queue using Binary Min-heap
Due Date   :  11/20/2024
*******************************************************/

#include <iostream>
#include <vector>
#include <exception> 
#include "PriorityQueue.h"

using namespace std; 

int main(){
    PriorityQueue<int> pq;

    pq.displayQueue();

    //pq.deleteMin();
    
    pq.insert(34);
    pq.insert(7);
    pq.insert(56);
    pq.insert(12);
    pq.insert(89);
    pq.insert(23);
    pq.insert(45);
    pq.insert(9);
    pq.insert(67);
    pq.insert(27);

    pq.displayQueue();
    cout << endl;

    pq.insert(8);
    pq.insert(25);

    pq.displayQueue();
    cout << endl;

    pq.deleteMin();

    pq.displayQueue();

   



/*

int main() {

    //template from homework 4
    PriorityQueue queue;
    //ask user for set of values for priority queue
    int values;
    const int VALUES = 50;
    int valueArray[VALUES];
    cout << "Enter set of values for a priority queue (enter -1 to stop): ";
    cin >> values;
    int i = 0;
    //reads values til -1 is read
    while(values > 0)
    {
        queue.insert(values);
        cin >> values;
        i++;
    }
    while(1)
    {
        cout << endl;
        cout << "Select one of the following operations: ";
        cout << endl;
        cout << "1. Insert an item into the heap";
        cout << endl;
        cout << "2. Delete the min";
        cout << endl;
        cout << "3. Print array representation of queue";
        cout << endl;
        cout << "4. Exit";
        cout << endl;

        //ask user to enter operation choice
        int userChoice;
        cout << "Enter operation: ";
        cin >> userChoice;

        if(userChoice == 4)
            break;

        switch(userChoice)
        {
            //case 1 - ask user to insert new value
            case 1:
            {
                int newVal;
                cout << endl;
                //ask user to insert a new value
                cout << "Enter new value to insert: ";
                cin >> newVal;
                queue.insert(newVal);
                break;
            }
            //case 2 - delete old minimum value and print new minimum value
            case 2:
            {
                int minVal;
                cout << endl;
                //print new minimum value
                cout << "New minimum value is: ";
                cout << queue.deleteMin();
                cout << endl;
                break;
            }
            //case 3 - print priority queue
            case 3:
            {
                //print priority queue
                queue.printQueue();
                break;
            }

            //case 4 - exit program
            case 4:
            {
                cout << "Exiting program";
                cout << endl;
                break;
            }
            //print error message for invalid operation
            default:
                cout << "Error! Invalid Choice!";
                cout << endl;
        }
    }
    return 0;
}


*/

}