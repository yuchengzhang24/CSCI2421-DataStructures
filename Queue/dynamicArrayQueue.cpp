#include <iostream>
using namespace std; 

class Queue{
    private: 
        int *array;
        int maxSize; 
        int endOfQueue;
    public: 
        Queue(int size){
            array = new int[size];
            maxSize = size; 
            endOfQueue = -1;
        }

        bool isEmpty(){
            if (endOfQueue == 0){
                return true;
            }
            else{
                return false;
            }
        }

        void resize(int s){
            int *tempArray = array;
            array = new int[s];

            for (int index = 0; index < min(s, endOfQueue+1); index++){
                array[index] = tempArray[index];
            }
            maxSize = s;
        }

        //Insert at the end
        void enqueue(int data){
            if (endOfQueue = maxSize-1){
                resize(2 * maxSize);
            }
            else{
                array[++endOfQueue] = data;
            }
        }

        //Remove at beginning
        int dequeue(){
            if (endOfQueue >= 0){
                int returnVal = array[0];

                for (int index = 0; index < endOfQueue; index++){
                    array[index] = array[index+1];
                }

                endOfQueue--;
                //endOfQueue is decreased by one

                return returnVal;
            }
            else {
                return -1000000;
                //Invalid value indicating queue is empty
            }
        }

        int peek(){
            if (endOfQueue >= 0){
                return array[0];
            }
            else{
                return -1000000;
                //Invalid value indicating queue is empty
            }
        }

};