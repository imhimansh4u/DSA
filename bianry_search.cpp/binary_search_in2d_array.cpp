#include<iostream>
#include<algorithm>
#include<vector>
                        // This is a program to demostrate binary search in 2D array //
                        // Here the whole matrix must be sorted (i.e. -- both col and row wise) //
                        //and the successer row or col must also be sorted (means phle wale row ke sare elements
                        // se bde elements aaeenge next row me .. same for col also)

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();                 //rows
        int col = matrix[0].size();              //columns
        int i = 0;                             //to traverse from starting 
        int j = (row*col)-1;                       //to traverse from end
        while(i<=j){
            int mid = i + (j-i)/2;
            int element = matrix[mid/col][mid%col]; /*Here (mid/col) is used to find the row of the matrix in which 
                                       mid index is present (take some examples and rough solve it to understand)
                                       and (mid%col) gives the column number as (0 to (col-1)) are possible column numbers
                                                                                        */
            if(element == target){
                return 1;
            }
            else if(element > target){
                j = mid -1;
            }
            else{
                i = mid+1;
            }
        }
        return 0;
    }
};
int main(){
    // write the remaining easy part to implement
    return 0;
}

//NOTE--  when you are studying this solution ..dont forget to look forward to see the que. no. (240) of leetcode
// que. name --- (Search a 2D Matrix II)