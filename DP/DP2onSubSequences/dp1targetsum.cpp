// Given an array arr of n integers and an integer target, determine if there is a subset of the given array with 
// a sum equal to the given target.


// Example 1

// Input: arr = [1, 2, 7, 3], target = 6

// Output: True

// Explanation: There is a subset (1, 2, 3) with sum 6.

// Example 2

// Input: arr = [2, 3, 5], target = 6

// Output: False

// Explanation: There is no subset with sum 6.

#include <iostream>
#include <vector>
using namespace std;


// Only Recursion -->> No dp --->>> T.C.-> O(2^n)
class Solution1{   
public:
    bool solve(vector<int>& arr,int i,int target){
        if(target == 0) return true;
        if(i == 0) return (arr[i] == target);
        // two conditions -> Take or not Take
        bool notTake = solve(arr,i-1,target);
        bool take  = false;
        // Only take if the target>arr[i]
        if(target >= arr[i]){
            take = solve(arr,i-1,target-arr[i]);
        }
        return (take || notTake);
    }
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        int i = n-1;
        return solve(arr,i,target);
    }
};

// Recursion + Memoization   -- > T.C. is O(n*target) , where n is the size of the array 
class Solution2{   
public:
    bool solve(vector<int>& arr,int i,int target,vector<vector<int>>& dp){
        if(target == 0) return true;
        if(i == 0) return (arr[i] == target);
        if(dp[i][target] != -1) return dp[i][target];
        // two conditions -> Take or not Take
        bool notTake = solve(arr,i-1,target,dp);
        bool take  = false;
        // Only take if the target>arr[i]
        if(target >= arr[i]){
            take = solve(arr,i-1,target-arr[i],dp);
        }
        return dp[i][target] = (take || notTake); //  If false then 0 , if true then 1
    }
    bool isSubsetSum(vector<int>& arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        int i = n-1;
        return solve(arr,i,target,dp);
    }
};

// Now Using Tabulation to reduce the extra space taking by the recursion stack

class Solution3{   
public:
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        for(int i=0;i<n;i++){
            dp[i][0] = true; //  It means if target is 0, it can be achieved at any index (so marked true)
        }
        dp[0][arr[0]] = true;
        for(int i=1;i<n;i++){
            for(int t=1;t<=target;t++){
                // Not take
                bool not_take = dp[i-1][t];
                bool take = false;
                if(arr[i] < t){
                    take = dp[i-1][t-arr[i]];
                }
                dp[i][t] = take || not_take;
            }
        }
        return dp[n-1][target];       
    }
};
// Now Tabulation +  space Optimization
// class Solution{   
// public:
//     bool solve(vector<int>& arr,int i,int target,vector<vector<int>>& dp){
//         if(target == 0) return true;
//         if(i == 0) return (arr[i] == target);
//         if(dp[i][target] != -1) return dp[i][target];
//         // two conditions -> Take or not Take
//         bool notTake = solve(arr,i-1,target,dp);
//         bool take  = false;
//         // Only take if the target>arr[i]
//         if(target >= arr[i]){
//             take = solve(arr,i-1,target-arr[i],dp);
//         }
//         return dp[i][target] = (take || notTake); //  If false then 0 , if true then 1
//     }
//     bool isSubsetSum(vector<int>arr, int target){
//         int n = arr.size();
//         vector<vector<int>> dp(n,vector<int>(target+1,-1));
//         int i = n-1;
//         return solve(arr,i,target,dp);
//     }
// };
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        vector<bool> curr(target+1,false);
        vector<bool> prev(target+1,false);
        prev[0] = true;
        curr[0] = true;
        if(arr[0] <= target)
            prev[arr[0]] = true; //  Beucase currently for prev i is 0
        for(int i=1;i<n;i++){
            for(int t=1;t<=target;t++){
                // Not take
                bool not_take = prev[t];
                bool take = false;
                if(arr[i] <= t){
                    take = prev[t-arr[i]];
                }
                curr[t] = take || not_take;
            }
            prev = curr;
        }
        return prev[target];       
    }
};


int main() {
    
    return 0;
}
