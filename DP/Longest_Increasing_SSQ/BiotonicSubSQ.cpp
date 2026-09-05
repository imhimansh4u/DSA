/**
 * Given an array arr of n integers, the task is to find the length of the longest bitonic sequence. 
 * A sequence is considered bitonic if it first increases, then decreases. The sequence does not have to be contiguous.


Example 1 ...............................

Input: arr = [5, 1, 4, 2, 3, 6, 8, 7]

Output: 6

Explanation: The longest bitonic sequence is [1, 2, 3, 6, 8, 7] with length 6.
 */



 // The Logic Is Simple ---------->>>>>>>>>>> Find the LIS from the Left upto that index and find the LIS from right upto that index
 // and take Left2Right[i] + Right2Left[i] -1 , bcs one element is repeated i.e. taken 2 times 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  // Find longest increasing subsq from both dirn at each index and then find the sum from both side and return the maximum one
    int LongestBitonicSequence(vector<int> arr) {
        int n = arr.size();
        vector<int> R2L(n,1);
        vector<int> L2R(n,1);
        int ans = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j] < arr[i]){
                    L2R[i] = max(L2R[j]+1,L2R[i]);
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(arr[j] < arr[i]){
                    R2L[i] = max(R2L[j]+1,R2L[i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            ans = max(ans,L2R[i]+R2L[i]-1);
            cout<<L2R[i]<<" "<<R2L[n-i-1]<<endl;
        }
        return ans;
    }
};


int main() {
    
    return 0;
}