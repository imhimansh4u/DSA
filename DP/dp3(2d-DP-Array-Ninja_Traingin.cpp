//             Problem Statement 
// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities.
//(Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, 
// he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?
// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum 
// number of merit points that Ninja can earn.

// For Example
// If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.

#include<iostream>
#include<vector>
using namespace std;

// APPROACH 1-> Recursion + 2-D dp + Memoization , reduces T.C to O((n*3)*3) and S.C. to O(n) overall (TopDown APproach)
//  This is Memoization (Top - Down ) Approach of this Problem --> think about its T.C. And S.C. by your own
class Solution1{
    public:
    long long solve(vector<vector<int>> &points,int ind,int prev,vector<vector<long long>> &dp){
        if(ind < 0){
            return 0;
        }
        long long curr = 0;
        for(int i=0;i<3;i++){
            if(i != prev){
                if(dp[ind][i] != -1){
                    curr = max(curr,dp[ind][i]);
                }else{
                    long long temp = solve(points,ind-1,i,dp);
                    dp[ind][i] = temp + points[ind][i];
                    curr = max(curr,dp[ind][i]);
                }
            }
        }
        return curr;
    }
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        int ind = n-1; 
        int prev = -1;
        vector<vector<long long>> dp(n,vector<long long>(3,-1));
        long long finalans = solve(points,ind,prev,dp);
        return (int)finalans;
    }
};

// APPROACH->2  --> Using Tabulation Bottom Up approach ,(Removes Extra O(n) of the recursion stack) , still required O(n*3) for dp array
class solution2{
    public:
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        // Write your code here.
        vector<vector<long long>> dp(n,vector<long long>(3,-1));
        int prev = -1;
        dp[0][0] = points[0][0];
        dp[0][1] = points[0][1];
        dp[0][2] = points[0][2];
        for(int i=1;i<n;i++){
            long long curr = 0;
            for(int j=0;j<3;j++){
                long long temp = 0;
                for(int k=0;k<3;k++){
                    if(k != j){
                        temp = max(temp,dp[i-1][k]+points[i][j]);
                    }
                }
                curr = max(curr,temp);
                dp[i][j] = temp;
            }
        }
        long long ans = 0;
        for(int i = 0;i<3;i++){
            ans = max(ans,dp[n-1][i]);
        }
        return (int)ans;
    }
};

// APPROACH-3 -->>  The Ultimate Space Optimization approach O(1) space because of a fixed size vector size 
class solution3{
    public:
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        // Write your code here.
        vector<long long> helper(3);
        helper[0] = points[0][0];
        helper[1] = points[0][1];
        helper[2] = points[0][2];
        vector<long long> h = helper;
        for(int i=1;i<n;i++){
            long long curr = 0;
            for(int j=0;j<3;j++){
                long long temp = 0;
                for(int k=0;k<3;k++){
                    if(k!=j){
                        temp = max(temp,helper[k]+points[i][j]);
                    }
                }
                curr = max(curr,temp);
                h[j] = temp;
            }
            helper = h;
        }
        long long ans = 0;
        for(int i=0;i<3;i++){
            ans = max(ans,helper[i]);
        }
        return (int)ans;
    }
};
int main(){
    
    return 0;
}