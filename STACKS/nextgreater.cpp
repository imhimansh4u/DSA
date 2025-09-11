// Given an array , return another array with next greater elements present on the right side in the array..
#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int main(){
vector<int> nums2 = {1,3,5,7,2,90,45,23,76};
vector<int> nextGreater(nums2.size(), -1); // To store next greater elements for nums2
    stack<int> s; // Monotonic decreasing stack
    // Preprocess next greater elements for nums2
    for (int i = nums2.size() - 1; i >= 0; --i) {
        while (!s.empty() && s.top() < nums2[i]) {
            s.pop();
        }
        if (!s.empty()) {
            nextGreater[i] = s.top();
        }
        s.push(nums2[i]);
    }
    for(int i = 0 ;i<nextGreater.size();i++){
        cout<<nextGreater[i]<<" ";
    }
    return 0;
}
