// ALL THE BELOW QUSTIONS IS SOLVED FOR MAXHEAP ONLY..
#include<iostream>
#include<algorithm>
using namespace std;
class Heap{
    public:
    int size;
    int arr[100] ;            // random big size
    Heap(){
        this->size = 0;
        arr[0] = -1;
    }
    void insert(int value){
        size = size + 1;
        int index = size;
        arr[index] = value;   // Here we are doing 1 based indexing
        while(index>1){
            int parent = index/2;  // find the parent element index
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    // Delete Function (To delete the root element)
    void DeleteFromHeap(){
        if(size == 0){
            cout<<"There is nothing to delete"<<endl;
            return;
        }
        //step 1 )) copy the last element to the root element
        int i = 1;
        arr[i] = arr[size];
        size--;
        // step 2)) check
        while(i<size){
            int leftChildIndex = 2*i;
            int rightChildIndex = 2*i + 1;
            if(leftChildIndex <= size && arr[leftChildIndex] > arr[i]){
                swap(arr[leftChildIndex], arr[i]);
                i = leftChildIndex;
            }
            else if(rightChildIndex<=size && arr[rightChildIndex]>arr[i]){
                swap(arr[rightChildIndex],arr[i]);
                i = rightChildIndex;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i = 1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
// Heapify Function ....
void heapify(int arr[], int size,int i){    // Dry Run to easily understand 
    // T.C. OF THIS ALGORITHM IS O(logn) .....
    int largest = i;
    int left  = 2 * i;
    int right = 2*i+1;
    if(left<size && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<size && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }
}   

int main(){
    Heap h1;
    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);
    h1.print();
    h1.DeleteFromHeap();
    cout<<"After deletion the heap will look like"<<endl;
    h1.print();
    int arr[8] = {-1,1,20,3,4,50,70,60};
    int n  = 8;
    for(int i = n/2;i>0;i--){
        heapify(arr,8,i);
    }
    // 
    cout<<"Now print all the elements"<<endl;
    for(int i = 1;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
