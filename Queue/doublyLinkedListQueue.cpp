#include <iostream>
using namespace std; 

class Node{
    private: 
        int data;
        Node *nextNodePtr;
        Node *prevNodePtr;
    public: 
        Node();
        void setData(int);
        int getData();
        void setNextNodePtr(Node*);
        Node *getNextNodePtr();
        void setPrevNodePtr(Node*);
        Node *getPrevNodePtr();
};

class Queue{
    private:
        Node *headPtr;
        Node *tailPtr;
    public: 
        Queue(){
            headPtr = new Node();
            tailPtr = new Node();
            headPtr -> setNextNodePtr(0);
            tailPtr -> setPrevNodePtr(0);
        }

        Node* getHeadPtr(){
            return headPtr;
        }

        Node *getTailPtr(){
            return tailPtr;
        }

        bool isEmpty(){
            if (headPtr -> getNextNodePtr() == 0){
                return true;
            }
            else{
                return false;
            }
        }

        void enqueue(int data){
            Node* newNodePtr = new Node();
            newNodePtr -> setData(data);
            newNodePtr -> setNextNodePtr(0);

            Node* lastNodePtr = tailPtr -> getPrevNodePtr();

            if (lastNodePtr == 0){
                headPtr -> setNextNodePtr(newNodePtr);
                newNodePtr -> setPrevNodePtr(0);
            }
            else {
                lastNodePtr -> setNextNodePtr(newNodePtr);
                newNodePtr -> setPrevNodePtr(lastNodePtr);
            }

            tailPtr -> setPrevNodePtr(newNodePtr);
        }

        int dequeue(){
            Node *firstNodePtr = headPtr -> getNextNodePtr();
            Node *nextNodePtr = 0;

            int poppedData = -10000; //empty queue

            if(firstNodePtr != 0){
                nextNodePtr = firstNodePtr->getNextNodePtr();
                poppedData = firstNodePtr -> getData();
            }
            else{
                return poppedData; 
            }

            if (nextNodePtr != 0){
                nextNodePtr -> setPrevNodePtr(0);
                headPtr -> setNextNodePtr(nextNodePtr);
            }
            else{
                headPtr -> setNextNodePtr(0);
                tailPtr -> setPrevNodePtr(0);
            }
            return poppedData;
        }

        int peek(){
            Node *firstNodePtr = headPtr -> getNextNodePtr();

            if (firstNodePtr != 0){
                return firstNodePtr -> getData();
            }
            else {
                return -100000; //empty queue
            }
        }
};