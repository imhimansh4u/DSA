/*QUE.--
Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1).
Find all possible paths that the rat can take to reach from source to destination.
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the
 matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other
cell. In case of no path, return an empty list. The driver will output "-1" automatically.  */
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    private:
    //below is the function to check that next vlock can be visited or not..
        bool isvalid(vector<vector<int>> mat,vector<vector<int>> track,int i,int j,int n){
            if((i>=0 && i<n) && (j>=0 && j<n) && track[i][j] == 0 && mat[i][j] == 1){
                return true;
            }
            return false;
        }
        void solve(vector<vector<int>> mat,vector<string> &ans,string output,vector<vector<int>> track,int i,int j,int n){
            int dummy_i = i;
            int dummy_j = j;
            // base case
            if(i==(n-1) && j == (n-1)){
                ans.push_back(output);
                return;
            }
            track[i][j] = 1;  // means now path (i,j) are visited so marked as 1
            // we can perform four operations --(up,down,left,right)
            //------->>>>>>>
            //for up
            dummy_i =i-1;
            dummy_j = j ;
            if(isvalid(mat,track,dummy_i,dummy_j,n)){
                output.push_back('U');
                solve(mat,ans,output,track,dummy_i,dummy_j,n);
                output.pop_back();  // it means backtracking    
            }
            //for down
            dummy_i = i+1;
            dummy_j = j;
            if(isvalid(mat,track,dummy_i,dummy_j,n)){
                output.push_back('D');
                solve(mat,ans,output,track,dummy_i,dummy_j,n);
                output.pop_back();
            }
            // for left
            dummy_i = i;
            dummy_j = j-1;
            if(isvalid(mat,track,dummy_i,dummy_j,n)){
                output.push_back('L');
                solve(mat,ans,output,track,dummy_i,dummy_j,n);
                output.pop_back();
            }
            // for right
            dummy_i = i;
            dummy_j =j+1;
            if(isvalid(mat,track,dummy_i,dummy_j,n)){
                output.push_back('R');
                solve(mat,ans,output,track,dummy_i,dummy_j,n);
                output.pop_back();
            }
            track[i][j] = 0; // again make the visited paths as 0.. so that alternate paths can be delievered
        }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        if(mat[0][0] == 0){
            return ans;
        }
        string output = "";
        int i = 0;
        int j = 0;
        int n = mat.size();
        //track function will keep record that a block is already visited or not
        vector<vector<int>> track = mat;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){ //initiallised with all 0 (means) no path visited yet
                track[i][j] = 0;
            }
        }
        solve(mat,ans,output,track,i,j,n);
        return ans;
    }
};
int main(){
    vector<vector<int>> mat = {{1,0,1,1},
                                {1,1,0,0},
                                {0,0,0,0},
                                {1,1,0,1}};
    vector<string> ans;
    Solution s1;
    ans = s1.findPath(mat);
    // Print the resulting paths
    if(ans.size() == 0) {
        cout << "No paths found" << endl;
    } else {
        cout << "Paths found:" << endl;
        for(string path : ans) {
            cout << path << endl;
        }
    }
    return 0;
}