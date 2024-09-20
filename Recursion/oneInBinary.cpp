// Write a recursive function that returns the number of 1 in the binary representation of N. Use the fact that this is equal to the number of 1 in the representation of N/2, plus 1 if N is odd.

#include <iostream>
using namespace std; 

int binary(int n){
  if (n == 1 || n == 0){
    return n;
  }
  else {
    if ( n % 2 != 0){
      return binary(n/2) + 1;
    }
    else {
      return binary(n/2);
    }
  }
}

int main (){
  cout << binary(125) << endl;
}