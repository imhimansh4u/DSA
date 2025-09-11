#include<iostream>
using namespace std;
void insertion_sort(int arr[],int n){
    int i=1;
    while(i<n){
        int j = i-1;
        int temp = arr[i];
        while(j>=0){
            if(arr[j]>temp){
                arr[j+1] = arr[j];       // shifting process
            }
            else{
                break; // it means array is already sorted .. so break form the loop...      
            }
            j--;
        }
        arr[j+1] = temp; // because the j pointer is on the previous element(which is less than temp)..so(j+1)
                            // will be the required position to fit temp.....
        i++;
    }
}

int main(){
    int n;
    cout<<"Enter the total no. of elements:: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<< i+1 << " element :: "<<endl;
        cin>>arr[i];
    }
    insertion_sort(arr,n);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}