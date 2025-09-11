#include<iostream>
#include<vector>
#include<algorithm>
  /*          TASK ::-- Rotate a square matrix by 90 degrees in cloakwise direction                    */


using namespace std;
// METHOD 1)) -- By taking a extra matrix ..


// void rotate(vector<vector<int>> &arr){
//     int row = arr.size();
//     int col = arr[0].size();
//     // here it is performed for a 2D matrix .. so the (row = col) ::
//     vector<vector<int>> ans(row,vector<int>(col));
//     for(int i = 0;i<row;i++){
//         for(int j=0;j<col;j++){
//             ans[i][j] = arr[row-j-1][i];
//         }
//     }
//     //again copying the rotated array in the original way
//     for(int i = 0;i<row;i++){
//         for(int j=0;j<col;j++){
//             arr[i][j] = ans[i][j];
//         }
//     }
    
// }

//METHOD 2 -- by without taking any extra matrix (in place swapping in the same matrix)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //firstly flipping across main dioganal
        for(int i =0;i<n;i++){
            for(int j = (i+1);j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //now flipping in mirror way
        for(int i = 0;i<n;i++){
            for(int j = 0;j<(n/2);j++){
                swap(matrix[i][j],matrix[i][n-j-1]);
            }
        }
    }
};

int main(){
    Solution s1;
    int n;
    int m;
    cout<<"Enter total rows:: ";
    cin>>n;
    cout<<"Enter tota; columns:: ";
    cin>>m;

    vector<vector<int>> arr(n,vector<int>(m));
    cout<<"Enter the elements of the matrix :: "<<endl;
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl<<"The original array is ::"<<endl;
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    s1.rotate(arr);        // to rotate the array by 90 degree clockwise
    cout<<"Array after rotation is :: "<<endl;
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}