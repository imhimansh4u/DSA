/*                                                   <-TASK-> 
Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers
 into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible
 order (i.e., sorted in ascending order). 
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        // find the rightmost element which is smaller than its next element
        int n = arr.size();
        int pivot = -1;
        int pivot_index = -1;
        for(int i=(n-1);i>=0;i--){
            if(arr[i-1] < arr[i]){
                pivot_index = i-1;
                pivot = arr[i-1];
                break;
            }
        }
        if(pivot_index == -1){   // it means no next permutation is possible
            sort(arr.begin(),arr.end());
            return;
        }
        int justgreater = INT_MAX;
        int justgreater_index = -1;
        // find the exact greter element than the pivot in its rightmost side
        
        for(int i = pivot_index + 1;i<n;i++){
            if(arr[i]>pivot && arr[i]< justgreater){
                justgreater = arr[i];
                justgreater_index = i;
            }
        }
        // Now swap the pivot element with the just greater element
        int temp = arr[pivot_index];
        arr[pivot_index] = arr[justgreater_index];
        arr[justgreater_index] = temp;
        // Now sort the array from pivot_index+1 to last
        sort((arr.begin()+pivot_index + 1),arr.end());
    }
};

int main(){

    return 0;
}