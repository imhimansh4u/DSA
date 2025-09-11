#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
// power of b to a using recursion
int power(int a, int b){
    if(a == 0){
        return 0;
    }
    else if(b == 0){
        return 1;
    }
    return a*power(a,b-1);
}
// reverse a string using recursion
void reverse_it(string& arr,int s){
    int n = arr.size();
    
    if(s>(n-s-1)){
        return;
    }
    swap(arr[s],arr[n-s-1]);
    reverse_it(arr,s+1);
}

int main(){
    string arr = "Himanshu";
    int e = arr.size();
    reverse_it(arr,0);
    cout<<arr<<endl;
    int a,b;
    cout<<"Enter value of a :: ";
    cin>>a;
    cout<<"Enter value of b :: ";
    cin>>b;
    cout<<power(a,b);
    return 0;
}