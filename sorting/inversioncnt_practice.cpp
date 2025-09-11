#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int merge(vector<int> &arr, int s, int e,int mid){
    int n1 = mid-s+1;
    int n2 = e - mid;
    int count = 0;
    vector<int> arr1(n1);
    vector<int> arr2(n2);
    //left part copy karo
           // k is the index to use in the main array
    for(int i = 0;i<n1;i++){
        arr1[i] = arr[s+i];
    }
    //right part copy karo

    for(int i = 0;i<n2;i++){
        arr2[i] = arr[mid+1+i];
    }
    // merge karo
    int i1 = 0;  // using double pointer
    int i2 = 0;
    int k = s;
    while(i1<n1 && i2<n2){
        if(arr1[i1]<arr2[i2]){
            arr[k] = arr1[i1];
            i1++;
            k++; 
        }
        else{
            arr[k] = arr2[i2];
            i2++;
            k++;
            count += n1-i1;
        }
    }
    while(i1<n1){
        arr[k++] = arr1[i1++];
    }
    while(i2<n2){
        arr[k++] = arr2[i2++];
    }
    return count;
}
int sortingandcount(vector<int> &arr,int s,int e){
    int count = 0;
    int mid;
    // base case
    if(s<e){
        mid = s + (e-s)/2;
    
        // sort left part
        count += sortingandcount(arr,s,mid);
        //sort right part 
        count += sortingandcount(arr,mid+1,e);
        // merge
        count += merge(arr,s,e,mid);
    }
    return count;
}


int main(){
    vector<int> arr = {4,3,2,1};
    cout<<sortingandcount(arr,0,3)<<endl;
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}