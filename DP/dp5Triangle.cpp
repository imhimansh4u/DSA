/***
 * Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the 
current row, you may move to either index i or index i + 1 on the next row.
Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
 */

#include <iostream>
#include <vector>
#include<climits>
using namespace std;




//soln1-> Using Memoization ->  T.c. -> Around O(n^2) and same s.c.
class Solution {
public:

    // Very Important Observation -> Often we initialise our dp array by -1 , but in this case , -1 can be value of a sum also,
    // so initialise it with such a value that cannot occur ..
    int solve(vector<vector<int>>& triangle,vector<vector<int>>& dp,int i,int j,int n){
        if(i == n-1){
            dp[i][j] = triangle[i][j];
            return dp[i][j];
        }
        if (dp[i][j] != 10000000) {
            return dp[i][j];
        }
        int d = solve(triangle,dp,i+1,j,n);  //down
        int dg =  solve(triangle,dp,i+1,j+1,n);   //  diagonal
        dp[i][j] = min(d,dg) + triangle[i][j];
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle){
        int n = triangle.size();
        
        vector<vector<int>> dp(n,vector<int>(n,10000000));
        int i = 0;
        int j= 0;
        int ans = solve(triangle,dp,i,j,n);
        return ans;
    }
};

// IN this you can also go from down to top
// Tabulation 
// discuss space and Time Complexity 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        dp[0][0] = triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<(n-(n-i)+1);j++){
                int up = dp[i-1][j];
                int prev = (j-1>=0 ? dp[i-1][j-1] : INT_MAX);
                dp[i][j] = min(up,prev) + triangle[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};
// space Optimization + tabulation -> Only O(n) s.c.
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n,INT_MAX);
        dp[0] = triangle[0][0];
        for(int i=1;i<n;i++){
            vector<int> help(n,INT_MAX);
            for(int j=0;j<(n-(n-i)+1);j++){
                int up = dp[j];
                int prev =  (j-1>=0 ? dp[j-1] : INT_MAX);
                help[j] = min(up,prev) + triangle[i][j];
            }
            dp = help;
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,dp[i]);
        }
        return ans;
    }
};


int main() {
    
    return 0;
}