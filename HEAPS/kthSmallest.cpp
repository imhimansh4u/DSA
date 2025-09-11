/*Given an array arr[] and an integer k where k is smaller than the size of the array,
 the task is to find the kth smallest element in the given array.*/

 // Here We will use property of heap(using stl proirity queue)
 #include<iostream>
 #include<queue>
 #include<vector>
 using namespace std;
 class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    // here in this function T.C. is O(nlogk)   ....................................
    int kthSmallest(vector<int> &arr, int k) {
        // step 1)-> insert first k elements in the heap
        priority_queue<int> pq;
        for(int i = 0;i<k;i++){
            pq.push(arr[i]);
        }
        // step 2)
        for(int i = k ;i<arr.size();i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        int ans = pq.top();
        return ans;
    }
};
 int main(){
 
     return 0;
 }