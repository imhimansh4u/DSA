#include <iostream>
#include <vector>
using namespace std;
#include<climits>
// The MOTO is simple , find the length of the longest increasing subsequence in the array 



int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> LIS;
    LIS.push_back(arr[0]);
    for(int i=1;i<n;i++){
        int ele = arr[i];
        if(LIS.size() == 0 || ele > LIS[LIS.size()-1]){
            LIS.push_back(ele);
        }else{
            int s = 0;
            int e = LIS.size()-1;
            while(s <= e){
                int mid = s + (e-s)/2;
                int prev = (mid == 0 ? INT_MIN : LIS[mid-1]);
                int next = (mid == LIS.size()-1 ? INT_MAX : LIS[mid+1]);
                if(ele > prev && ele < next){
                    LIS[mid] = ele;
                    break;
                }else if(LIS[mid] < ele){
                    s = mid+1;
                }else e = mid-1;  // it means arr[mid] > ele
            }
        }
    }
    cout<<LIS.size();
    return 0;
}


////////                    ALGPRITHM ./..................................................................
/*


Maintain a vector LIS.
LIS[k] stores the smallest possible ending value of an increasing subsequence of length k+1.
For every ele:
If ele > LIS.back(), append it.
Otherwise, find the first element >= ele using binary search and replace it with ele.

Why is replacement allowed?
Suppose:

LIS = [2, 5, 7]

and ele = 3.

Replace:

[2, 5, 7] -> [2, 3, 7]

Length stays the same, but 3 is a better tail than 5.

Why better?
Because any future number that could come after 5 can also come after 3, and maybe some smaller numbers can come after 3 too.

So we are not losing any chance of getting a longer LIS.

Example:

arr = [10, 9, 2, 5, 3, 7, 101, 18]

LIS becomes:

[10]
[9]
[2]
[2,5]
[2,3]
[2,3,7]
[2,3,7,101]
[2,3,7,18]

Final:

LIS.size()

gives the correct length of LIS.

But LIS itself may not be the actual subsequence from the original array.

For example, during replacements, values may come from different subsequences. We only care about maintaining the best possible tail for every length.

The one line to remember:

We replace a larger tail with a smaller tail because a smaller ending value gives us more chances to extend the subsequence later, without reducing its current length.

Time complexity:

O(n log n)

because every element performs one binary search.

*/
