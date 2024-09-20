//Write a C++ program to calculate the factorial of a given number using recursion.
#include <iostream>
using namespace std;

int factorial(int n){
  if (n == 1 || n == 0){
    return 1;
  }
  else {
    return n * factorial(n-1);
  }
}

int main(){
  cout << factorial(5);
}