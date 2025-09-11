#include<iostream>
using namespace std;
void swapit(int *p1,int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(){
    int n;
    cout<<"ENter the total no. of elements:: ";
    cin>>n;
    int arr[n];
    int swapped_numbers = 0;
    for(int i=0;i<n;i++){
        cout<<"Enter the "<< i+1 << " element :: "<<endl;
        cin>>arr[i];
    }
    for(int i = 0;i<n-1;i++){
        bool swapped = false;   /* it is the method to optimize our code that if any element is not swapped in
                                 any internal loop it means in that the array is already sorted and we need not 
                                 to check for further values of (i) so we break from the loop*/
        for(int j=0;j<(n-1-i);j++){
            if(arr[j]>arr[j+1]){
                swapit(&arr[j],&arr[j+1]);
                swapped = true;
                swapped_numbers++;
            }
        }
        if(swapped == false)
        break;
    }
    cout<<endl<<"Now the sorted array is :: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Total no.of swaps:: "<<swapped_numbers;
    return 0;
}
