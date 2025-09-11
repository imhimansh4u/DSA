/*
Problem statement---------->>>>>>>>>>>>>>>

You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.

Each time, you can climb either one step or two steps.

You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.
*/
#include<iostream>
using namespace std;
int count_ways(int n){        // n = (total no. of steps to climb) 
    //base case
    if(n < 0){
        return 0;
    }
    else if(n == 0){  //suppose he is standinf at the same step ,so he have 1 way to go on that same step
        return 1;
    }
    //recursive call
    return count_ways(n-1) + count_ways(n-2);
}
int main(){
    int nstairs;
    cout<<"Enter total no. of stairs :: "<<endl;
    cin>>nstairs;
    cout<<"Total no. of ways to reach upto that stairs is :: "<<endl;
    cout<<count_ways(nstairs);
    return 0;
}