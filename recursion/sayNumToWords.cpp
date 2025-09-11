#include<iostream>
#include<string>
using namespace std;
// this problem will print any number into words 
void numToWords(int n, string arr[]){
    // base case
    if(n == 0){
        return;
    }
    //recursive call
    numToWords(n/10 , arr);         // here it is a not return type function thats why i have not used return here 
    //printing 
    cout<<arr[n%10]<<" ";
}

int main(){
    string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int num;
    cout<<"Enter the number to get it in words:: ";
    cin>>num;
    numToWords(num,arr);
    return 0;
}