// Leetcode 62
// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the
// bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The test cases are generated so that the answer will be less than or equal to 2 * 109.

#include <iostream>
#include <vector>
using namespace std;

// soln 1-> Recuresion + Memoization + dp array
class Solution {
public:
    int solve(int& m,int &n,int i,int j,vector<vector<int>> &dp){
        if(i<0 || i>=m || j<0 || j>=n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int left = solve(m,n,i,j-1,dp);
        int up = solve(m,n,i-1,j,dp);
        dp[i][j] = left+up;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0] = 1;
        int i = m-1;
        int j = n-1;
        return solve(m,n,i,j,dp);
    }
};


// soln2 -> Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 && j == 0){
                    continue;
                }
                int left = (j-1>=0 ? dp[i][j-1] : 0);
                int right = (i-1>=0 ? dp[i-1][j] : 0);
                dp[i][j] = left+right;
            }
        }
        return dp[m-1][n-1];
    }
};

// soln3 -> space optimization + tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++) {
            vector<int> curr(n, 0);

            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    curr[j] = 1;
                    continue;
                }

                int left = (j - 1 >= 0 ? curr[j - 1] : 0);
                int up = (i - 1 >= 0 ? prev[j] : 0);

                curr[j] = left + up;
            }

            prev = curr;
        }

        return prev[n - 1];
    }
};
int main() {
    
    return 0;
}