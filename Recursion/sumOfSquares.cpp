//Write a C++ program to implement a recursive function to calculate the sum of squares. 

#include <iostream>
using namespace std; 

int sumOfSquares(int n){
  if (n == 1){
    return 1;
  }
  else {
    return (n * n) + sumOfSquares(n-1);
  }
}

int main (){
  cout << sumOfSquares(4) << endl;
}