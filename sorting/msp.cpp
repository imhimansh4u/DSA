/*
#include<iostream>
using namespace std;

// function for merging
void merge(int arr[],int s,int e,int mid){
    int n1 = mid-s+1;
    int n2 = e-mid;
    int arr1[n1];        // to copy the elements from left side.
    int arr2[n2];        // to copy the elements from right side.
    // copy elements from left side into temporary array
    for(int i=0;i<n1;i++){
        arr1[i] = arr[s+i];
    }
    // copy elements from right side into temporary array
    for(int i=0;i<n2;i++){
        arr2[i] = arr[mid+1+i];
    }
    int i = 0;
    int j = 0;
    int k = s;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr[k++] = arr1[i++];
        }
        else if(arr1[i]>arr2[j]){
            arr[k++] = arr2[j++];
        }
        else{
            arr[k++] = arr1[i++];
            arr[k++] = arr2[j++];
        }
    }
    while(i<n1){
        arr[k++] = arr1[i++];
    }
    while(j<n2){
        arr[k++] = arr2[j++];
    }
}
// function for merge sort
void mergesort(int arr[],int s,int e){
    int mid = s + (e-s)/2;
    if(s>=e){
        return ;
    }
    // left part ko sort kr do
    mergesort(arr,s,mid);
    //right part ko sort kr do
    mergesort(arr,mid+1,e);
    // merge kr do
    merge(arr,s,e,mid);
}

int main(){
    int arr[5] = {2,1,4,6,7};
    cout<<"Before sorting :: "<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergesort(arr,0,4);
    cout<<"After sorting "<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
*/
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &arr, int s,int e, int mid){
    // phle do arrays bnao jisme left ar right part ko copy kroge
    int n1 = mid-s+1;
    int n2 = e-mid;
    int tarr1[n1];
    int tarr2[n2];
    for(int i = 0;i<n1;i++){
        tarr1[i] = arr[s+i];
    }
    for(int i = 0;i<n2;i++){
        tarr2[i] = arr[mid+i+1];
    }
    // ab dono part ko merge krna hai
    int i1 = 0;
    int i2 = 0;
    int k = s; // for tracking of the main index
    while(i1<n1 && i2 < n2){
        if(tarr1[i1] < tarr2[i2]){
            arr[k++] = tarr1[i1];
            i1++;
        }
        else{
            arr[k++] = tarr2[i2];
            i2++;
        }
    }
    while(i1<n1){
        arr[k++] = tarr1[i1++];
    }
    while(i2<n2){
        arr[k++] = tarr2[i2++];
    }
}
void mergesort(vector<int> &arr,int s,int e){
    int mid  = s + (e-s)/2;
    // base case
    if(s>=e){
        return;
    }
    // left part ko sort kr do
    
    mergesort(arr,s,mid);
    //right part ko sort kr do
    mergesort(arr,mid+1,e);
    // right and left part ko merge kr do
    merge(arr,s,e,mid);
}

int main(){
    vector<int> v = {4,2,86,26,476,3,6,3,543,533,24,332,353};
    mergesort(v,0,v.size()-1);
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}