// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;

// // THis Approacc uses T.C. of (n*n) // So we have to minimise the t.c. of this also 


// int solve(vector<int> &arr,vector<vector<int>> &dp,int i,int base,int n){
//     if(i>=n) return 0;  
//     if(base != -1 && dp[i][base] != -1) return dp[i][base];
//     int take = 0;
//     int not_take = solve(arr,dp,i+1,base,n);
//     if(base == -1 || arr[i] < arr[base]){
//         // it means take it 
//         take = 1 + solve(arr,dp,i+1,i,n);
//     }
//     return dp[i][base] = max(take,not_take);
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     vector<vector<int>> dp(n,vector<int>(n,-1));
//     cout<<solve(arr,dp,0,-1,n);
//     return 0;
// }

//Now tabulation  approach


/**

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// THis Approacc uses T.C. of (n*n) and s.c. of O(n*n) // removed recursion space stack 


// Starting from index i, what is the maximum LIS length I can form,
// when the last element I have already selected is at index prev?    , that is what dp state shows here 

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--){
        for(int prev = i-1;prev>=-1;prev--){
            int not_take =  dp[i+1][prev+1];  // means starting from index i+1 and taking base as prev+1 , bcs current index ko hm base na lena chahte hai
            int take = 0;
            if(prev == -1 || arr[i] > arr[prev]){
                take = 1+dp[i+1][i+1];  // here base is also done i+1 instead of i because dp stores prev as prev+1
            }
            dp[i][prev+1] = max(take,not_take);
        }
    }
    cout<<dp[0][0];
    return 0;
}


* */ 

/****
 *  3rd and even simpler Approach --------------->>>>>>>>>>> direct method 
 * 
 * here dp[i] will store the longes increasing subsequence ending at index i , means (index i wala element included)
 * 
 */
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(n,1); // sb khud ko leke longes LIS 1 ka to ho hi skta hai 
    vector<int> hash(n);  // This will simply store the path to find the LIS , just by backtracking it 
    for(int i=0;i<n;i++){
        hash[i] = i; //  because initially each carry a LIS pointing to them Only 
    }
    int ans = 1;
    int lisInd = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j] < arr[i]){
                if(dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
                if(dp[i] > ans){
                    ans = max(ans,dp[i]);
                    lisInd = i;
                }
            }
        }
    }
    int temp = lisInd;
    vector<int> LIS;
    while(hash[temp] != temp){
        LIS.push_back(arr[temp]);
        temp = hash[temp];
    }
    LIS.push_back(arr[temp]);
    reverse(LIS.begin(),LIS.end());
    for(int ele:LIS) cout<<ele<<" ";
    return 0;
}

