#include <iostream>
#include <vector>
#include<string>
using namespace std;

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