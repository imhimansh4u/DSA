// AGGRESSIVE COWS PROBLEM
//Problem statement --->>>
/*
You are given an array with unique elements of stalls[], which denote the position of a stall.
You are also given an integer k which denotes the number of aggressive cows.
Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.
*/

/*APPROACH AND ALGORITHM
1.) Here we will firtly calculate all possible values ,that can be a diffrence between two cows.
    a.) The minimum possible distance between any two cows is 1.
    b.) The maximum possible distance between any two cows is (maximum_stall - minimum_stall)
2.) Now we will do Binary search among these possible answers .
    a.) We will make ans variable that will store the possible answer and we have to maximize it. initially(ans = 0)
    b.) We will check that if for any perticular mid value , it is possible to place the cows or not 
        a.) If possible , then we check if (mid > ans) then update (mid=ans) . and now we will search for any bigger value so (start = mid+1)
        b.) If not possible , then we will search any smaller value of mid , therefore (end = mid-1)
3.) Now logic of possible function
    a.)We will sort the array
    b.) Now we make lastCowPos , which will track the position of cow which is given its stall currently and initialise it with(lastCowPos = stalls[0])
    c.)Now We will check that if stalls[i]-lastCowpos > mid .. it means that cow can be placed at that stall and update the lastCowPos also ..
    d.) if all the cows are placed then return true that yes , with this value of (minimum distance between two cows ), we can place all the cows
    e.) Otherwise Return false.... 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    bool possible(vector<int> &stalls,int possible_ans,int cows){
        int n = stalls.size();
        int c = 1;   // it will help to count the no. of cows that has been placed
        int lastcowpos = stalls[0];
        for(int i = 1;i<n;i++){
            if((stalls[i]-lastcowpos)>=possible_ans){
                c++;
                lastcowpos = stalls[i];
            }
            if(c == cows){
                return true;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int n = stalls.size();
        int ans = 0;
        int start = 1;
        int end = stalls[n-1]-stalls[0];
        while(start<=end){
            int mid = start + (end-start)/2;
            if(possible(stalls,mid,k)){
                if(mid>ans){
                    ans = mid;
                    start = mid+1;
                }
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};
int main(){

    return 0;
}