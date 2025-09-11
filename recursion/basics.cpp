#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void forward_print(int n){
    //base case
    if(n==0){
        return;
    }
    // recursive relation
    forward_print(n-1);
    cout<<n<<" ";
}
void reverse_print(int n){
    //base case
    if(n==0){
        return;
    }
    cout<<n<<" ";
    // recursive relation
    reverse_print(n-1);
}
//  To find nth fibonacci 
int fib(int n){
    // base case
    if(n==1 ){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}
// To check if the array is sorted or not
bool is_sorted(int arr[],int n,int idx){
    //n is the size of array
    if(idx == (n-1)){
        return true;
    }
    //getting answer of the smaller problem 
    bool recursion_res = is_sorted(arr,n,idx+1);
    // final check
    bool ans = recursion_res && (arr[idx] <= arr[idx+1]);
    return ans;
    //or-->>
    // return (is_sorted(arr,n,idx+1) && (arr[idx]<= arr[idx+1]));
}

//recursive function to return the sum of elements in a array..
int sum_in_array(int arr[] , int n){
    //base case
    if(n == 0){
        return 0;
    }
    //recursive call
    return arr[n-1]  + sum_in_array(arr,n-1);
}


int main(){
    //printing the numbers 
    int n;
    cout<<"Enter n:: ";
    cin>>n;
    cout<<endl;
    forward_print(n);
    cout<<endl;
    reverse_print(n); 
    cout<<endl;
    cout<<"The "<<n<<" fibonacii number is :: "<<fib(n); 
    int arr[] = {1,2,3,4,5,6,7,8};
    int arr2[] = {3,5,7,6,9,0};
    cout<<endl;
    cout<<"sorted of not:: "<<is_sorted(arr,8,0)<<endl;
    cout<<"sorted of not:: "<<is_sorted(arr2,6,0)<<endl;
    // to find the sum in an array
    cout<<"sum of the elememts in the aray is :: ";
    cout<<sum_in_array(arr,8)<<endl;
    cout<<"sum of the elememts in the aray is :: ";
    cout<<sum_in_array(arr2,6);
    return 0;
}