/*Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.
Note: If a window does not contain a negative integer, then return 0 for that window.   (GFG problem)
*/

// APPROACH 1-)  T.C.-> O(N*K) ,, where (N = size of array) and (K = window size)..
#include<iostream>
#include<vector>
#include<deque>
using namespace std;


class Solution {
  public:
    int firstnegative(vector<int> arr, int p1,int p2){
        int ans = 0;
        for(int i=p1;i<=p2;i++){
            if(arr[i]<0){
                ans = arr[i];
                break;
            }
        }
        return ans;
    }
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        vector<int> ansarr;
        if(arr.size() == 1){
            if(arr[0]<0){
                ansarr.push_back(arr[0]);
            }
            else{
                ansarr.push_back(0);
            }
            return ansarr;
        }
        int p1 = 0;
        int p2 = p1+(k-1);
        while(p2<=arr.size()-1){
            int ans = firstnegative(arr,p1,p2);
            ansarr.push_back(ans);
            p1++;
            p2++;
        }
        return ansarr;
    }
};

// APPROACH 2) By the help of DEQUE......  T.C. ->> O(n) , where n = size of the array..
class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        deque<int> dq;
        vector<int> ans;    // array to store the answer and return it....
        // firstly process the first window
        for(int i=0;i<k;i++){
            if(arr[i]<0){
                dq.push_back(i);
            }
        }
        // Now push the answer of first window into our answer array
        if(dq.size()>0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        // Now process the other remaining windows
        for(int i=k;i<arr.size();i++){
            // first pop the extra element
            if(!dq.empty() && (i-dq.front() >=k)){
                dq.pop_front();
            }
            // Now add the extra elementt (puting the current element)
            if(arr[i]<0){
                dq.push_back(i);
            }
            // Now push the first negative for perticular window in ans array
            if(dq.size()>0){
                ans.push_back(arr[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        
        return ans;
    }
};
