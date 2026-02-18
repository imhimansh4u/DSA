/*QUE..--
Given an integer array arr[]. Find the contiguous sub-array(containing at least one number) that has the maximum sum and return its sum.
*/

/*  KANDANES ALGORITHM HIGHLIGHTS
Kadane's Algorithm works by maintaining a running sum of the subarray and updating the maximum sum when a higher sum is
found. The key insight is that if the running sum becomes negative, it's better to reset it to zero
(i.e., start a new subarray), since continuing with a negative sum will only decrease the overall sum.
*/

//CODE
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int current_max= 0;
        int global_max = INT_MIN;
        for(int i = 0;i<n;i++){
            current_max += arr[i];
            if(current_max > global_max){
                global_max = current_max;
            }
            if(current_max < 0){
                current_max = 0;
            }
        }
        return global_max;
    }
};
int main(){
    int n;
    cout<<"Enter the value of n :: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The largest sum of contigous sub array is :: "<<endl;
    Solution s1;
    cout<<s1.maxSubarraySum(arr);
    return 0;
}