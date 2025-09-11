#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr,int s,int e){
    int pivot = arr[s];
    int count=0;
    for(int i = s+1;i<=e;i++){
        if(arr[i]<=arr[s]){
            count++;
        }
    }
    int p = s+count;
    swap(arr[p],arr[s]);
    int i = s;
    int j = e;
    
    while(i<p &&  j>p){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<p &&  j>p){
            swap(arr[i],arr[j]);
        }
    }
    return p;
}
void sorting(vector<int> &arr,int s,int e){
    // base case 
    if(s>=e){
        return;
    }
    int pivot = partition(arr,s,e);
    sorting(arr,s,pivot-1);
    sorting(arr,pivot+1,e);
}
void quickSort(vector<int> &arr)
{
    int s = 0;
    int e = arr.size() -1;
    sorting(arr,s,e);
}
int main(){
    vector<int> arr = {2,53,6,53,5,54};
    int n = arr.size();
    quickSort(arr);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}