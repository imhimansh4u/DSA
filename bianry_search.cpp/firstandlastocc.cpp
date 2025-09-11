/*             Programme to find the first and last occurance using binary search 
                with time complexity --- O(log(n))*/



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        vector<int> ans;
        int i = 0;
        int j = (n-1);
        int first_occ = -1;
        int last_occ = -1;
        // program to find the first occurance   
        while(i<=j){
            int mid = i + (j-i)/2;
            if(arr[mid] == x){
                first_occ = mid;    /* store the answer in an variable and now check in the left part
                                             that any x is present or not */
                j = mid-1;          // to check in the left part
            }
            else if(arr[mid] < x){
                i = mid +1;
            }
            else{
                j = mid -1;
            }
        }
        ans.push_back(first_occ);
        // now code for last occurance
        i = 0;
        j = (n-1);
        while(i<=j){
            int mid = i + (j-i)/2;
            if(arr[mid] == x){
                last_occ = mid;  /*store the answer in an variable and check any other x is present in right 
                                    part or not as its last occurance   */
                i = mid+1;
            }
            else if(arr[mid]<x){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        ans.push_back(last_occ);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;     // dont take tension about this
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends