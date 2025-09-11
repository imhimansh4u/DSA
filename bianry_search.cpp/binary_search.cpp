#include<iostream>
#include<algorithm>
using namespace std;
int binary_search(int arr[],int n,int key){
    int i = 0;     // i is starting here ........
    int j = n-1;   // j is last/end here ........
    while(i<=j){
        /*
        int mid = (i+j)/2;            //this is not optimized method to find mid:
        */
    //    OPTIMIZED METHID TO FIND THE VALUE OF MID ELEMENT :: 
    int mid = i + (j-i)/2;    
        if(arr[mid] == key){
            cout<<"Key found at index :: ";
            return mid;
        }
        else if(arr[mid]<key){
            i = mid+1;
        }
        else{
            j = mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    int key;
    cout<<"Enter the value of n and key respectively :: ";
    cin>>n;
    cin>>key;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr , arr + n);              // built function to sort an array............
    for(int i=0;i<n;i++){             // for loop to print the sorted array..........
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<binary_search(arr,n,key);
    return 0;
}  