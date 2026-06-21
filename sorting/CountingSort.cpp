// // study COUNTINGSORT INFO FROM NET , BELOW QUE DEPICTS ITS USE
// It is a sweltering summer day, and a boy wants to buy some ice cream bars.

// At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

// Note: The boy can buy the ice cream bars in any order.

// Return the maximum number of ice cream bars the boy can buy with coins coins.

// You must solve the problem by counting sort.

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Implmenting Counting sort to solve this question
        // find maxi
        int n = costs.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,costs[i]);
        }
        vector<int> help(maxi+1,0);
        for(int i=0;i<n;i++){
            help[costs[i]]++;
        }
        // Now prefix sum
        for(int i=1;i<help.size();i++){
            help[i] += help[i-1];
        }
        // now actual sorted array
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            help[costs[i]]--;
            ans[help[costs[i]]] = costs[i];
        }   
        // Now actual q solving
        int res = 0;
        for(int i=0;i<n;i++){
            if(coins >= ans[i]){
                coins -= ans[i];
                res++;
            }else break;
        }
        return res;
    }
};

int main(){
    return 0;
}


