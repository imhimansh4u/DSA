#include<iostream>
using namespace std;
bool linear_search(int arr[], int target,int n){   // n is the last index of arr -->> (array.length-1)
    n -=1;
    if(n<0){
        return false;
    }
    else if(arr[n] == target){
        return true;
    }
    return linear_search(arr,target,n-1);
}
bool binary_search(int arr[], int target , int s, int e){
    // base case
    if(s>e){
        return false;
    }
    int mid = s + (e-s)/2;
    // 2nd base case
    if(arr[mid] == target){
        return true;
    }
    //recursive calls
    if(arr[mid]<target){
        return binary_search(arr,target,mid+1,e);
    }
    else if(arr[mid]>target){
        return binary_search(arr,target,s,mid-1);
    }
}
int main(){
    int arr[] = {1,2,3,4,5};
    int target;
    cout<<"Enter target :: ";
    cin>>target;
    cout<<linear_search(arr,target,5);
    cout<<endl<<"Now Binary search :: "; // note that for binary seach array must be sorted 
    cout<<binary_search(arr,target,0,4);
    return 0;
}
