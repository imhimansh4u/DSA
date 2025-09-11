#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any 
extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.
*/
class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {   // Do DRY RUN to understand the code
        // code here
        int n = a.size();
        int m = b.size();
        int i = n-1;
        int j = 0;
        while(i>=0 && j<m){
            if(a[i]<b[j]){
                break;
            }
            else if(b[j]<=a[i]){
                swap(a[i],b[j]);
                i--;
                j++;
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }
};
int main(){

    return 0;
}