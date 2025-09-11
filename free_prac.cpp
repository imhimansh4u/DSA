// // #include <bits/stdc++.h>
// // using namespace std;
// // int find(vector<int> arr, int e){
// //     for(int i = 0;i<arr.size();i++){
// //         if(arr[i] == e)
// //             return i;
// //     }
// //     return -1;
// // } 
// // int nextGreat(vector<int> B,int ele){
// //     int maxi = -1;
// //     int i = find(B,ele);
// //     for(int j = i;j<B.size();j++){
// //         if(B[j] > ele){
// //             maxi = B[j];
// //             break;
// //         }
// //     }
// //     return maxi;
// // }
// // vector<int> nextGreaterElement(int n, vector<int> A, int m, vector<int> B) {
// //     // Write your code here.
// //     vector<int> ans;
// //     for(int i=0;i<n;i++){
// //         int nmax = nextGreat(B,A[i]);
// //         ans.push_back(nmax);
// //     }
// //     return ans;
// // }


// // int main(){
// //     vector<int> ans;
// //     vector<int> A = {1,2,0,3,4,5};
// //     int n = 6;
// //     vector<int> B = {3,5,0,2,1,6,4};
// //     int m = 7;
// //     ans = nextGreaterElement(n,A,m,B);
// //     for(int i = 0;i<ans.size();i++){
// //         cout<<ans[i]<<" ";
// //     }
// //     return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;
// /*

// class Solution {
    
//   public:
//     bool allzero(vector<vector<int>> mat,int i){
//         int size = mat.size();
//         for(int j = 0;j<size;j++){
//             if(mat[i][j] != 0){
//                 return false;
//             }
//         }
//         return true;
//     }
//     bool check(vector<vector<int>> mat , int i){
//         int index = 0;
//         while(index<mat.size()){
//             if(index == i){
//                 continue;
//             }
//             else{
//                 if(mat[index][i] != 1){
//                     return false;
//                 }
//             }
//             index++;
//         }
//         return true;
//     }
//     // Function to find if there is a celebrity in the party or not.
//     int celebrity(vector<vector<int> >& mat) {
//         for(int i = 0;i<mat.size();i++){
//             if(allzero(mat,i) && check(mat,i)){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };
// */
// class Solution {
//   public:
//   // function to check that all the elements in that row is 0 or not(means potential_celebrity should know no one)
//     bool allzero(vector<vector<int> >& mat ,int potential_celebrity){
//         for(int j = 0;j<mat.size();j++){
//             if(mat[potential_celebrity][j] != 0){
//                 return false;
//             }
//         }
//         return true;
//     }
//     //function to check that all the elements in the column of potential_celebrity is 1 or not except diagonal element(it means all people know the celebrity) and we leave the case(where celebrity knows himself)
//     bool check(vector<vector<int> >& mat ,int potential_celebrity){
//         for(int i = 0;i<mat.size();i++){
//             if(i == potential_celebrity){
//                 continue;
//             }
//             else{
//                 if(mat[i][potential_celebrity] != 1){  // it means i should know potential...
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
    
//     // Function to find if there is a celebrity in the party or not.
//     int celebrity(vector<vector<int> >& mat) {
//         stack<int> s;
//         int n = mat.size();
//         for(int i =0;i<n;i++){
//             s.push(i);
//         }
//         while(s.size() != 1){
//             int a = s.top();
//             s.pop();
//             int b = s.top();
//             s.pop();
//             if(mat[a][b] != 1){
//                 s.push(a);
//             }
//             if(mat[b][a] != 1){
//                 s.push(b);
//             }
//         }
//         int potential_celebrity = s.top();
//         if(allzero(mat,potential_celebrity) && check(mat,potential_celebrity))
//             return potential_celebrity;
//         return -1;
        
//     }
// };
// int main(){
//     vector<vector<int>> q = {{0,1,0,0},{0,0,0,0},{0,1,0,0},{0,1,0,0}};
//     Solution s;
//     int ans = s.celebrity(q);
//     cout<<ans;
// }


// #include <bits/stdc++.h> 
// int maxi(int a, int b){
//     if(a>=b){
//         return a;
//     }
//     else{
//         return b;
//     }
// }
// int binaryGap(int num) {
//     // Write your code here.
//     int max_dis = 0;
//     int count = 0;
//     while(num>0){
//         if(num&1 == 1){
//             count = 1;
//             num>>1;
//             while(num&1 == 0){
//                 count++;
//                 num>>1;
//             }
//             max_dis = maxi(max_dis,count);
//         }
//         else{
//             num>>1;
//         }
//     }
//     return max_dis;
// }
#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>>  insert(int n){
    vector<vector<long long>> ans;
    for(int i = 1; i < n ;i++){
        for(int j = i+1;j<=n;j++){
            vector<long long> subans;
            subans.push_back(i);
            subans.push_back(j);
            ans.push_back(subans);
        }
    }
    return ans;
}

int main(){
    vector<vector<long long>> ans;
    ans = insert(5);
    int n = ans.size();
    int m = ans[0].size();
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<ans[i][j]<<",";
        }
        cout<<endl;
    }
    return 0;
}
