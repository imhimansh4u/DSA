/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(string &s,string &t,int i,int j,vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = solve(s,t,i-1,j-1,dp) + solve(s,t,i-1,j,dp);  // means current matching element ko leke next element of t pe chala gaya + current matching element ko na leke dusra matching element khojne nikl gaya ......
        }
        return dp[i][j] = solve(s,t,i-1,j,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n<m) return 0;
        if(n == m){
            if(s == t) return 1;
            return 0;
        }
        cout<<n<<" "<<m;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s,t,n-1,m-1,dp);
    }
};

int main() {
    
    return 0;
}


/*
THe Logic here is only ki when you get a matching element you have two options 
1. Us matching element ko le lo and next element pe move kr jao search krne ke lie
2. Us matching element ko skip kr do t me j same jgh rkho and same character ko string s me ar jgh dhundo kyuki wo fir tmhe 
   ar possible strings denge 
*/