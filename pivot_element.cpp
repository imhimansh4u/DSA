#include<iostream>
#include<vector>
using namespace std;
// pivot element question.....
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int mid = s + (e-s)/2;
        int left_sum = 0;
        int right_sum = 0;
        for(int i =s;i<=mid-1;i++){
            left_sum += nums[i];
        }
        for(int i =mid+1;i<=e;i++){
            right_sum += nums[i];
        }
        while(mid>=s+1 && mid<=e-1){
            if(right_sum == left_sum){
                return mid;
            }
            else if(left_sum < right_sum){
                mid+=1;
                left_sum += nums[mid-1];
                right_sum -= nums[mid];
            }
            else{
                mid-=1;
                right_sum += nums[mid+1];
                left_sum -= nums[mid];
            }
        }
        if(mid == 0 && right_sum == 0 ){
            return mid;
        }
        else{
            return -1;
        }
    }
};