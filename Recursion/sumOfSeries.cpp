//Write a C++ program to implement a recursive function to calculate the sum of a series. 

#include <iostream>
using namespace std; 

int sumOfSeries(int n){
  if (n == 1){
    return 1;
  }
  else 
    return n + sumOfSeries(n-1);
}

int main() {
  cout << sumOfSeries(4) << endl;
}