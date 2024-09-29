#include <iostream>
using namespace std;

class Node {
    private: 
        int data;
        Node* next;
    public:
        Node(){
            data = 0;
            next = NULL;
        }
        Node(int val){
            data = val;
            next = NULL;
        }
        Node(int val, Node* n){
            data=val;
            next= n;
        } 

        int getData() const {
            return data;
        }
        Node* getNext() const {
            return next;
        }

        void setData(int val){
            data = val;
        }
        void setNextPtr(Node* n){
            next = n;
        }

        void print() const{
            cout << data << endl;
        }
};

class Stack {
    private: 
        Node *headPtr;
    public:
        Stack(){
            headPtr = new Node();
            headPtr -> setNextPtr(NULL);
        }

        //Insert element at index 0 
        void push (int data){
            Node *current = headPtr -> getNext();
            Node *prev = headPtr; 
            Node *newNode = new Node(data, current);
            prev -> setNextPtr(newNode); 
        }

        //Delete element at index 0 
        void pop(){
            if(!isEmpty()){
                Node *current = headPtr -> getNext();
                Node *prev = headPtr;
                prev -> setNextPtr(current -> getNext());
                delete current;
            }
            else{
                cout << "Empty stack" << endl;
            }
        }

        //Check if stack is empty 
        bool isEmpty(){
            if(headPtr -> getNext() == NULL){
                return true;
            }
            else{
                return false;
            }
        }

        int peek(){
            if (!isEmpty()){
                Node *current = headPtr -> getNext();
                return current -> getData();
            }
            else{
                return -1;
            }
        }
            
}