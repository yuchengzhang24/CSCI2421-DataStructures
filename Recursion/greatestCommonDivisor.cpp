//Write a C++ recursive function definition to find the gcd of two positive integers using Euclidean algorithm.

#include <iostream>
using namespace std; 

int gcd(int m, int n){
  if (n == 0){
    return m;
  }
  else{
    return gcd(n, m % n);
  }
}

int main (){
  cout << gcd(126, 93) << endl;
}