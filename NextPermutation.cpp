#include <iostream>
#include<cmath>
#include<climits>
#include <vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNextsmallestGreater(vector<int> &nums,int ind){
        int ans = INT_MAX;
        int res = -1;
        for(int i=ind+1;i<nums.size();i++){
            if(nums[i]>nums[ind] && nums[i]<ans){
                ans = nums[i];
                res = i;
            }
        }
        return res;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        while(i>=0){
            if(nums[i]<nums[i+1]){
                int indi = findNextsmallestGreater(nums,i);
                swap(nums[i],nums[indi]);
                break;
            }
            i--;
        }
        if(i < 0){
            sort(nums.begin(),nums.end());
            return;
        }
        sort(nums.begin()+i+1,nums.end());
        return;
    }
};


int main() {
    
    return 0;
}

// ALGORITHM STEP
// Next Permutation — 4 Steps
// Find Pivot: From right, find the first index i such that a[i] < a[i+1].
// Find Successor: From right, find the smallest element greater than a[i].
// Swap: Swap the pivot a[i] with that element.
// Reverse: Reverse the part after the pivot to make it ascending.