//                      LEETCODE PROBLEM ->1463
/***
 * You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of
 *  cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
 

Example 1:


Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.
 */

#include <iostream>
#include <vector>
using namespace std;


//APPROACH 1-> Recursion + Memoization ->  T.C. -> O(n*m*m) and S.C. -> O(n*m*m) + O(n)->dp+recurstion stack space ,n->row and m->col
class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp,int &r,int &c,int i,int j1,int j2){
        if(j1<0 || j1>=c || j2<0 || j2>=c) return -1;
        if(i == r-1){
            if(j1 == j2){
                return grid[i][j1];
            }
            return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = -1;
        for(int k = -1;k<=1;k++){
            for(int p=-1;p<=1;p++){
                int value = 0;
                if(j1 == j2) value += grid[i][j1];
                else value += (grid[i][j1] + grid[i][j2]);
                value += solve(grid,dp,r,c,i+1,j1+k,j2+p);
                maxi = max(maxi,value);
            }
        }
        dp[i][j1][j2] = maxi;
        
        return dp[i][j1][j2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        int i = 0;
        int j1 = 0;
        int j2 = c-1;
        return solve(grid,dp,r,c,i,j1,j2);
    }
};

// APPROACH 2-> tABULATION -> Removes Extra Stack space
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
                if(j1 == j2) dp[m-1][j1][j2] = grid[m-1][j1];
                else dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }
        for(int i = m-2;i>=0;i--){
            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){
                    int maxi = -1;
                    for(int dj1=-1;dj1<=1;dj1++){
                        for(int dj2=-1;dj2<=1;dj2++){
                            int value = 0;
                            if(j1 == j2) value+=grid[i][j1];
                            else value += (grid[i][j1] + grid[i][j2]);
                            if(j1+dj1 >= 0 && j1+dj1<n && j2+dj2 >= 0 && j2+dj2<n){
                                value += dp[i+1][j1+dj1][j2+dj2];
                            }else value += -1;
                            maxi = max(maxi,value);
                        }
                    } 
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][n-1];
    }
}; 

// approach 3-> tabulation + space Optimization -> Reduce 3D dp array to 2D dp array 
// --> THink and do by Own -> (HINT ->  we dont require storing the row number , we can vary it ac to our use)
int main() {
    
    return 0;
}