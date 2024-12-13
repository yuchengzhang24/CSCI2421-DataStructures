//Given a sorted array of n integers and a target value, determine if the target exists in the array in logarithmic time using the binary search algorithm.

#include <iostream>
using namespace std; 

int binarySearch(int a[], int low, int high, int target){
  if (low > high){
    return -1; 
  }
  int mid = (high + low) / 2;

  if (target = a[mid]){
    return mid;
  } 
  else if (target < a[mid]){
    return binarySearch(a, low, mid -1, target);
  }
  else {
    return binarySearch(a, mid+1, high, target);
  }
}