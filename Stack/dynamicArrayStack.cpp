#include <iostream>
using namespace std; 

class Stack {
    private:
        int *array; 
        int maxSize; 
        int topOfStack;
    public: 
        Stack(int size){
            array = new int[size];
            maxSize = size;
            topOfStack = -1;
        } 

        bool isEmpty(){
            if (topOfStack == -1){
                return true;
            }
            else{
                return false;
            }
        }

        void resize (int s){
            int *tempArray = array;
            array = new int[s];

            for (int index = 0; index < min(s, topOfStack+1); index ++){
                array[index] = tempArray[index];
            }
            maxSize = s;
        }

        //Insert at end
        void push(int data){
            if (topOfStack = maxSize - 1){
                resize (2 * maxSize);
            }
            else{
                array[++topOfStack] = data;
            }
        }

        int peek(){
            if (topOfStack >= 0){
                return array[topOfStack];
            }
            else {
                return -1000000;
                //Invalid value to indicate empty stack 
            }
        }

        int pop(){
            if (topOfStack >= 0){
                return array[topOfStack--];
                //topOfStack is decreased by one after the vlaue is retrieved 
            }
            else {
                return -1000000;
                //Invalid value to indicate empty stack 
            }
        }

};
