//Write a C++ program to implement a recursive function to calculate the sum of digits of a given number.

#include <iostream>
using namespace std;

int sumOfDigits(int n){
  if (n >= 0 && n <=9){
    return n; 
  }
  else {
    return (n % 10) + sumOfDigits(n/10);
  }
}

int main (){
  cout << sumOfDigits(123) << endl;
}