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

class List {
    private:
        Node* headPtr;
    public: 
        List(){
            headPtr = new Node();
            headPtr -> setNextPtr(NULL);
        }

    void insert(int data){
        Node* current = headPtr -> getNext();
        Node* prev = headPtr;

        while (current != NULL){
            prev=current;
            current = current -> getNext();
        }

        Node* newNode = new Node(data, NULL);
        prev -> setNextPtr(newNode);
    }

    bool isEmpty(){
        if (headPtr -> getNext() == NULL){
            return true;
        }
        else {
            return false;
        }
    }

    void insertAtIndex(int index, int data){
        Node* current = headPtr -> getNext();
        Node* prev = headPtr;

        int i=0;
        while (current != NULL){
            if (i == index){
                break;
            }
            else {
                prev = current;
                current = current -> getNext();
                i++;
            }
        }

        Node* newNode = new Node(data, current);
        prev -> setNextPtr(newNode);
    }

    int read(int index){
        Node* current = headPtr; 
        int i = 0;
        while (current != NULL){
            if (i == index){
                return current -> getData();
            }
            else {
                current = current -> getNext();
                i++;
            }
        }
        return current -> getData();
    }

    void modifyElement(int index, int data){
        Node* current = headPtr -> getNext();
        Node* prev = headPtr;
        int i = 0;

        while (current != NULL){
            if (i == index){
                current -> setData(data);
                return;
            }
            else {
                prev = current;
                current = current -> getNext();
                i++;
            }
        }
    }

    void deleteItem(int deleteIndex){
        Node* current = headPtr -> getNext();
        Node* prev = headPtr;
        Node* nextPtr = NULL;
        int index = 0;

        while (current != NULL){
            if (index == deleteIndex){
                nextPtr = current -> getNext();
                break;
            }
            else{
                prev = current;
                current = current -> getNext();
                index++;
            }
        }
        prev -> setNextPtr(nextPtr);
    }

};





//https://excalidraw.com/#json=9xjcGKWpLDZBtM1jnKqYs,6HhSM40MffI2BN8_Fur4Sw