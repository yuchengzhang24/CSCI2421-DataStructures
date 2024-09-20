//Simulate the “Tower of Hanoi” recursive method using n > 3 (more than 3 disks).

#include <iostream>
using namespace std;

void TOH(int n, int A, int B, int C){
  if (n > 0){
    TOH(n-1, A, C, B);
    cout << "Moving a disk from " << A << " to " << C << endl;
    TOH(n-1, B, A, C); 
  }
}

int main(){
  TOH(4, 1, 2, 3);
}