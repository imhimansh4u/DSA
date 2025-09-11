/* TASK -->> Given an array arr[] that contains positive and negative integers (may contain 0 as well).
Find the maximum product that we can get in a subarray of arr[].
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
// APPROACH 1)) use nested loops to itereate for every possible subarray with two variables current_max and global_max ..update
// the current maximum in the running subarray and compare it with global_max if greater than updtae the global max..
// T.C. -->> O(N);



/*APPROACH-2)) -->>
[ Using minimum and maximum product ending at any index - O(n) Time and O(1) Space
Let's assume that the input array has only positive elements. Then, we can simply iterate from left to right keeping track of the
 maximum running product ending at any index. The maximum product would be the product ending at the last index. 
 The problem arises when we encounter zero or a negative element.

If we encounter zero, then all the subarrays containing this zero will have product = 0, so zero simply resets the product of the subarray.
If we encounter a negative number, we need to keep track of the minimum product as well as the maximum product ending at the previous index. This is because when we multiply the minimum product with a negative number, it can give us the maximum product. So, keeping track of minimum product ending at any index is important as it can lead to the maximum product on encountering a negative number.
*/
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int currmin = arr[0];
        int currmax = arr[0];
        int globalmax = arr[0];
        for(int i = 1;i<arr.size();i++){
            int temp = max({arr[i],currmin*arr[i],currmax*arr[i]});
            currmin = min({arr[i],currmin*arr[i],currmax*arr[i]});
            currmax = temp;
            if(globalmax < currmax){
                globalmax = currmax;
            }
        }
        return globalmax;
    }
};
/*APPROACH 3)) -->>
Here in this approach we will traverse and calculate the product from both starting and ending end ..
We are doing this to encounter with the problem when we get odd no. of negative integers in our current subaray ..
In this case , we have two options ,, either remove the first encountered negative , or the last encountered negative .. 
baki dry run and code ke through smjh le ...
*/
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        int leftToright = 1;   // for record of multiplication from left to right traversal
        int rightToleft = 1;   //for record of multiplication from right to left traversal
        int globalmax = INT_MIN;
        for(int i = 0;i<n;i++){
            if(leftToright == 0){
                leftToright = 1;
            }
            if(rightToleft == 0){
                rightToleft = 1;
            }
            // multiply from left to right
            leftToright *= arr[i];
            int j = n-i-1;   // calculating the opposite index.
            // NOw multiply from right to left
            rightToleft *= arr[j];
            globalmax = max({globalmax,rightToleft,leftToright});
        }
        return globalmax;
    }
};

int main(){

    return 0;
}