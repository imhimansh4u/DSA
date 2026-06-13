//                   PROBLEM
// A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step.
// To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference.
//The frog can jump from any step either one or two steps, provided it exists.
// Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.

#include <iostream>
#include <vector>
#include<climits>
using namespace std;

// ##1-> Recursive (Top-Down) Approach
class Solution {
public:
    int solve(vector<int>& heights,vector<int>& dp,int i){
        if(i<1) return 0;
        if(i == 1){
            return abs(heights[i]-heights[i-1]);
        }
        if(dp[i] != -1) return dp[i];
        dp[i] = min((solve(heights,dp,i-1) + abs(heights[i]-heights[i-1])),(solve(heights,dp,i-2) + abs(heights[i]-heights[i-2])));
        return dp[i];
    }
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n,-1);
        int ans = 0;
        ans = solve(heights,dp,n-1);
        return ans;
    }
};



// YPUR TASK -> DO tabulation approach of dp for this question , with O(n) tc also and O(1) tc also

// Problem statement Now changes to -> You can Jump K steps at a time .. and the rest remains same
//#####TASK ->  Wrtie the Recursive dp (top-down) approach by yourself -- HINt-> (Just add a loop of k)
class Solution {
public:
    int solve(vector<int> &heights,vector<int>& dp,int i,int &k){
        if(i==0) return 0;
        if(i==1) return abs(heights[i]-heights[i-1]);
        int j = i-1;
        int ans = INT_MAX;
        while(j>=0 && j>=(i-k)){
            if(dp[j] != -1) return (dp[j]+abs(heights[i]-heights[j]));
            ans = min(ans,(solve(heights,dp,j,k) + abs(heights[i]-heights[j])));
            j--;
        }
        return ans;
    }
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n,-1); 
        return solve(heights,dp,n-1,k);
    }
};
// Now tabulation Based Approach  (No faltu ka space for Recursion stack)
class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        if(n<1) return 0;
        vector<int> dp(n,-1);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int j=i-1;
            int ans = INT_MAX;
            while(j>=0 && j>=(i-k)){
                ans = min(ans,(dp[j] + abs(heights[i]-heights[j])));
                j--;
            }
            dp[i] = ans;
        }
        return dp[n-1];
    }
};



int main() {
    
    return 0;
}