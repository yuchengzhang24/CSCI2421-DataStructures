#include <iostream>
using namespace std; 

class BSTNode{
    private: 
        int data;
        BSTNode *left;
        BSTNode *right;
    public: 
    //constructors 
    BSTNode(): data(0), left(0), right(0){}                                         //default constructor: default value 0, left and right children point to NULL
    BSTNode(int val): data(val), left(0), right(0){}                                //initializing BST node with a specific value, left and right children point to NULL
    BSTNode(int val, BSTNode *l, BSTNode *r): data(val), left(l), right(r){}        //Initializes a BST node with a specific value pointing to a left and right child
    //accessor functions
    int getData() const{
        return data;
    }
    BSTNode *getLeft() const{
        return left;
    }
    BSTNode *getRight() const{
        return right;
    }
    //mutator functions 
    void setData(int val){
        data = val;
    }
    void setLeft(BSTNode *leftPointer){
        left = leftPointer;
    }
    void setRight(BSTNode *rightPointer){
        right = rightPointer;
    }
};

class BSTree{
    private: 
        BSTNode *root; 
    public: 
        BSTree(){                                                                   //default constructor, root points to NULL
            root = 0;
        }

        BSTNode *getRoot() const {
            return root;
        }
        bool isEmpty() const; 
        void insert(int data);
        void deleteNode(int data);
        BSTNode *find(int data);
        BSTNode *findRecursively(BSTNode *p, int key);
        BSTNode *BSTree::findMin(BSTNode *node);
        void traversePreOrder(BSTNode *p) const;
        void printPreOrder() const; 
        void traverseInOrder(BSTNode *p) const;
        void printInOrder() const; 
        void traversePostOrder(BSTNode *p) const;
        void printPostOrder() const; 
        BSTNode *minValue(BSTNode *node);
        BSTNode *maxValue(BSTNode *node);
};


//Finding a Node Iteratively
BSTNode *BSTree:: find(int data){                                                   //Finding a node - iterative solution
    bool found = false;                                                             //Boolean flag, initially mark as false 
    if(isEmpty()){                                                                  //check if the tree is empty 
        cout << "The tree is empty." << endl; 
        return 0;
    }

    BSTNode *current;                                                               //Temporary pointer used to traverse tree
    current = root;                                                                 //Initialize curret to point to the same pointer as root
    while(current != 0){                                                            //Loop: While current is not NULL
        if(current -> getData() == data){                                           //Check if current is the same value as the value we're looking for
            found = true;                                                           //If found, make flag true. 
            cout << "Data " << data << "had been found in the tree" << endl; 
            return current;                                                         //Return address of current
        }
        else{
            if (data > current -> getData()){                                       //If data is greater than current, move right
                current = current -> getRight();
            }
            else{
                current = current = current -> getLeft();                           //If data is less than current, move left
            }
        }
    }
    if(!found){                                                                     //If not found, return 
        cout << "Data not found" << endl; 
    }
    return 0;  
}


//Finding a Node Recursive Solution 
BSTNode *BSTree::findRecursively(BSTNode *p, int key){
    if (p == 0 || p -> getData() == key){                                            //If Tree is empty or key is the root, return root.
        return p;
    }
    else if (p -> getData() < key){
        return findRecursively(p -> getLeft(), key);                                //If data is less than key, go left and recall function
    }
    else {
        return findRecursively(p -> getRight(), key);                               //If data is more than key, go right and recall function
    }
}


//Finding Minumum Node (Nonrecursive)
BSTNode *minValue(BSTNode *node){
    BSTNode *current = node;
    while (current != 0 && current -> getLeft() != 0){                              //Loop: While current is not NULL and the left of current does not point to NULL, go left
        current = current ->getLeft();
    }

    return current;                                                                 //When the left of current points to NULL, we can say that is the mininum value and return that 
}


//Finding Minimum Node Recursive Solution 
BSTNode *BSTree::findMin(BSTNode *node){
    if (node == NULL){                                                              //If tree is empty, return NULL
        return NULL;
    }
    else if (node -> getLeft() == NULL){                                            //Else if the left child of node is NULL, you've reached the smallest value and return the node
        return node;
    }
    else{
        return findMin(node -> getLeft());                                          //Else recall the function recursively until you reach the minimum value
    }
}


//Finding Maximum Node (Nonrecursive)
BSTNode *maxValue(BSTNode *node){
    BSTNode *current = node;
    while (current != 0 && current -> getRight() != 0){                              //Loop: While current is not NULL and the right of current does not point to NULL, go right
        current = current ->getRight();
    }

    return current;                                                                 //When the right of current points to NULL, we can say that is the maximum value and return that 
}



//Insertion (Iterative Solution)
void BSTree::insert(int data){
    BSTNode *node = new BSTNode(data);                                              //Create a new BST node using this data
    BSTNode *parent = NULL;                                                         

    if(isEmpty()){                                                                  //Check if BST is empty. If yes, insert at root node. 
        root = node;
    }
    else{                                                                           
        BSTNode *current = root;                                                    //Current node to traverse tree, initialize it to point to root
        while(current){                                                             
            parent = current;
            if (node -> getData() > current -> getData()){                          //If the data we want to insert is greater than the data of current, go to the right
                current = current -> getRight();
            }
            else{                                                                   //If the data is less, go to the left
                current = current -> getLeft();
            }
        }
        if (node -> getData() < parent -> getData()){                               //Once we get to a leaf node, check the value of data with the value of the leaf node. If smaller, insert at the left
            parent -> setLeft(node);
        }
        else{
            parent -> setRight(node);                                               //If greater, insert at the right. 
        }
    }
}



//Pre-Order Traversal 
void BSTree::traversePreOrder(BSTNode *p) const{
    if (p != NULL){                                                                 //Until the root is not NULL
        cout << p -> getData() << " ";                                              //Read the root
        if (p -> getLeft()){                                                        //If left is not NULL, go to the left, recall traversePreOrder function recursively for left subtree
            traversePreOrder(p -> getLeft());
        }
        if (p -> getRight()){                                                       //IF right is not NULL, go to the right, recall traversePreOrder function recursively for right subtree
            traversePreOrder(p -> getRight());
        }
    }
}



//In-Order Traversal 
void BSTree::traverseInOrder(BSTNode *p) const{
    if (p != NULL){                                                                 //If the left of root is not null, go to the left
        if (p -> getLeft()){                                                        //Recall the function recursively
            traverseInOrder(p -> getLeft());
        }
        cout << p -> getData() << " ";                                              //Then print the root 
        if (p -> getRight()){                                                       //Then, if the right is not NULL, go to the right and recall the function recursively
            traverseInOrder(p -> getRight());
        }
    }
}



//Post-Order Traversal 
void BSTree::traversePostOrder(BSTNode *p) const{
    if(p != NULL){                                                                  //If the Root is not NULL
        if(p -> getLeft()){                                                         //If the left of root is not NULL, go left and recall the function recursively
            traversePostOrder(p -> getLeft());
        }
        if (p -> getRight()){                                                       //If the right of the root is not NULL, go to the right and recall the function recursively
            traversePostOrder(p -> getRight());
        }
        cout << p -> getData() << " ";                                              //Then print the root
    }
}
