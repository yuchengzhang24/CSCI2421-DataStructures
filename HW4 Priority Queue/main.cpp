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
    // declares an instance of Priority Queue with parameter type int. 
    PriorityQueue<int> pq;

    // prompt user to input values
    int input;
    cout << "Enter numbers. (-1 to stop): " << endl;
    while (true){
        cin >> input;
        if (input == -1){
            break;
        }
        pq.insert(input);
    }

    // prompt user to choose an option from menu 
    int choice;
    while (true){
        cout << "================================================================ \n"
             << "Choose from the following: \n"
             << " '1' : Insert a new item into priority queue.\n"
             << " '2' : Delete minimum item (top priority) from priority queue. \n"
             << " '3' : Display array representation of priority queue. \n"
             << " '4' : Exit program. \n"
             << "================================================================" << endl;

        cout << "Select an operation: "; 
        cin >> choice; 

        // switch statement for menu options
        switch (choice){
            case 1:
                int insertVal;
                cout << " Enter the number you'd like to enter into the priority queue: ";
                cin >> insertVal;
                pq.insert(insertVal);
                cout << " '" << insertVal << "' inserted into the priority queue." << endl;
                break;
            case 2: 
                cout << " '";
                pq.displayMin();
                cout << "' deleted from priority queue." << endl;
                pq.deleteMin();
                break;
            case 3:
                cout << " Array representation of priority queue: ";
                pq.displayQueue();
                break;
            case 4:
                cout << " Terminating program." << endl;
                cout << "================================================================" << endl;
                break;
            default:
                cout << " Error: Invalid Choice.";
                cout << endl;
                break;
        }

        if (choice == 4){
            break;
        }
    }
    
    return 0;
}