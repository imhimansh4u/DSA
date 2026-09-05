#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
using namespace std;



// Tabulation way of finding Longest Common Subsequence 
class Solution {
public:
    // Function to return the LCS string of text1 and text2
    string longestCommonSubsequence(string &text1, string &text2) {
        int n = text1.size();
        int m = text2.size();

        // Create DP table to store lengths of LCS for all substrings
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill dp table bottom-up
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    // Characters match: increase length by 1
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // Characters don't match: take max of left and top
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Reconstruct LCS string from dp table
        int i = n, j = m;
        string lcs = "";

        // Traverse dp table from bottom-right to top-left
        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                // Characters match, add to result and move diagonally
                lcs += text1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                // Move up if top cell has greater value
                i--;
            } else {
                // Move left otherwise
                j--;
            }
        }
        // Reverse string since it was built backwards
        reverse(lcs.begin(), lcs.end());

        return lcs;
    }
};

// Recursive Approach --> 
pair<int,string> solve(string &s1,string &s2,int i,int j,vector<vector<pair<int,string>>> &dp){
    if(i<0 || j<0){
        return {0,""};
    }
    if(dp[i][j].first != -1) return dp[i][j];
    if(s1[i] == s2[j]){
        auto ans = solve(s1,s2,i-1,j-1,dp);
        return dp[i][j] = {ans.first + 1,ans.second + s1[i]};
    }
    auto c1 = solve(s1,s2,i-1,j,dp);
    auto c2 = solve(s1,s2,i,j-1,dp);
    if(c1.first > c2.first){
        return dp[i][j] = c1;
    }else{
        return dp[i][j] = c2;
    }
}

int main() {
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);
    int n = s1.size();
    int m = s2.size();
    vector<vector<pair<int,string>>> dp(n,vector<pair<int,string>>(m,{-1,""})); 
    auto ans =  solve(s1,s2,n-1,m-1,dp);
    cout<<ans.first<<" "<<ans.second;
    return 0;
}
