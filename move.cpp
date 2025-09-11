/*      This is a programme to move all negative elements to one side of an array  */
#include<iostream>
using namespace std;
void shift(int arr[],int l,int r){
    while(l<=r){
        if(arr[l]<0 && arr[r]<0){
            l ++;
        } 
        else if(arr[l]>0 && arr[r]<0){
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
        else if(arr[l]>0 && arr[r]>0){
            r--;
        }
        else{
            l++;
            r--;
        }
    }
}
void display(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter the total no. of elements :: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<< i+1 << " element :: ";
        cin>>arr[i];
    }
    shift(arr,0,(n-1));
    display(arr,n);
    return 0;
}