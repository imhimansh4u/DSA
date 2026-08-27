// We have to find the length of the Longest Common Subsequence between Two Strings 
#include <iostream>
#include <vector>
using namespace std;

// This Programme will simply find the length of the Longest Common subsequence 
class Solution {
  public:
    int solve(string &str1,string &str2,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(str1[i] == str2[j]){
            return dp[i][j] = 1 + solve(str1,str2,i-1,j-1,dp);
        }
        return dp[i][j] = max(solve(str1,str2,i-1,j,dp),solve(str1,str2,i,j-1,dp));
    }
    int lcs(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(str1,str2,n-1,m-1,dp);
    }
};

// Now Tabulation APproach
class Solution2 {
  public:
    int lcs(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(str1[i] == str2[0]){
                dp[i][0] = 1;
            }else if(i>0){
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int j=0;j<m;j++){
            if(str1[0] == str2[j]){
                dp[0][j] = 1;
            }else if(j>0){
                dp[0][j] = dp[0][j-1]; 
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(str1[i] == str2[j]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};


int main() {
    
    return 0;
}