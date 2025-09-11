#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    // heapify function
    void heapify(vector<int> &arr,int index,int size){
        int largest = index;
        int left = 2*index + 1; 
        int right = 2*index + 2;
        if(left<size && arr[left]>arr[largest])
            largest = left;
        if(right<size && arr[right]>arr[largest])
            largest = right;
        if(largest != index){
            swap(arr[largest],arr[index]);
            heapify(arr,largest,size);
        }
    }
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        // Build max heap by heapifying from the last non-leaf node
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, i, n);
        }
        while(n-1>0){
            swap(arr[0],arr[n]);
            n--;
            // Now second step to is to put the element at its correct position by heapify function
            heapify(arr,0,n);
        }
    }
};

int main(){

    return 0;
}