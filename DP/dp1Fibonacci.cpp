#include <iostream>
#include <vector>
using namespace std;

//according to 1 based indexing   (Using Recursive dp) ->  T.C->O(n) and S.C.-> O(n) for recursive stack and O(n) for dp array 
int f(int n,vector<int> &dp){   // Here using the concept of Memoization (storing already Computed overlapping subproblems)
    if(n<=1) return n;
    if(dp[n] != -1) return dp[n];
    dp[n] = f(n-1,dp) + f(n-2,dp);
    return dp[n];
}


// Now this Approach is Tabulation Approach -> So, T.C.->  is O(n) but S.C. is O(n) only-> for the dp array , No Extra O(n) for the Recursive tech stack
// This is Tabulation (Bottom - Up)-> We starts from the base case and then Goes upto the Required ans.. 
int fiboTabulation(int n,vector<int>& dp){
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Now TO reduce that S.C. of O(n) also , we can cleverly use a technique here , Now T.C.->O(n) and S.C.->O(1)
int f3(int n){
    int prev2 = 0;
    int prev1 = 1;
    for(int i=2;i<=n;i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1,-1); 
    int ans = f(n,dp);
    cout<<ans<<endl;
    int ans2 = f3(n);
    cout<<ans2<<endl;
    return 0;
}


// REMEMBER->>
// For a i-1 and i-2 approcah in any question there will be always an space optimisation technique