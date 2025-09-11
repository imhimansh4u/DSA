/* leetcode (54) (spiral matrix)
        TO DO----->> get a new array of a 2d array in spiral way 
                   [[1,2,3],
                    [4,5,6],   ---->> [1,2,3,6,9,8,7,4,5]
                    [7,8,9]]
*/



#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> ans;                 //to store the final array
        int row = arr.size();
        int col = arr[0].size();
        int startrow = 0;
        int startcol = 0;
        int endrow = row-1;
        int endcol = col-1;
        int count = 0;
        int total = row*col;
        while(count<total){              // bcs total no. of elements in the ans arrays is total elements present 
                                            //in the 2d array matrix
            //printing the start row
            for(int index=startcol;count<total && index<=endcol;index++){
                ans.push_back(arr[startrow][index]);
                count++;
            }
            startrow++;
            //printing the end column
            for(int index = startrow;count<total && index<=endrow;index++){
                ans.push_back(arr[index][endcol]);
                count++;
            }
            endcol--;
            //printing the end row
            for(int index = endcol;count<total && index>=startcol;index--){
                ans.push_back(arr[endrow][index]);
                count++;
            }
            endrow--;
            //printing the start column
            for(int index = endrow;count<total && index>=startrow;index--){
                ans.push_back(arr[index][startcol]);
                count++;
            }
            startcol++;
        }
        return ans;
    }
};
int main(){
    Solution s;
    int row;
    int col;
    cout<<"enter the rows ::";
    cin>>row;
    cout<<"enter the columns ::";
    cin>>col;
    vector<vector<int>> arr(row , vector<int>(col));
    cout<<endl<<"Enter the elements of the matrix::"<<endl;
    for(int i=0;i<row;i++){
        for(int j = 0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"The matrix is:: "<<endl;
    for(int i=0;i<row;i++){
        for(int j = 0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Now the array in spiral form is::"<<endl;
    vector<int> ans;               // to store the answer
    ans = s.spiralOrder(arr);
    for(int i=0;i<(row*col);i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}