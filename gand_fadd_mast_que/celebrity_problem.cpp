/*A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. 
A square matrix mat is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith 
person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.
*/

#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
// User function template for C++

// first approach -->> with time complexity -->>O(n^2)
/*
class Solution {
    
  public:
    bool allzero(vector<vector<int>> mat,int i){
        int size = mat.size();
        for(int j = 0;j<size;j++){
            if(mat[i][j] != 0){
                return false;
            }
        }
        return true;
    }
    bool check(vector<vector<int>> mat , int i){
        int index = 0;
        while(index<mat.size()){
            if(index == i){
                index++;
            }
            else{
                if(mat[index][i] != 1){
                    return false;
                }
            }
            index++;
        }
        return true;
    }
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        for(int i = 0;i<mat.size();i++){
            if(allzero(mat,i) && check(mat,i)){
                return i;
            }
        }
        return -1;
    }
};
*/
// second approach -->>> with time complexity of O(n)
// User function template for C++

class Solution {
  public:
  // function to check that all the elements in that row is 0 or not(means potential_celebrity should know no one)
    bool allzero(vector<vector<int> >& mat ,int potential_celebrity){
        for(int j = 0;j<mat.size();j++){
            if(mat[potential_celebrity][j] != 0){
                return false;
            }
        }
        return true;
    }
    //function to check that all the elements in the column of potential_celebrity is 1 or not except diagonal element(it means all people know the celebrity) and we leave the case(where celebrity knows himself)
    bool check(vector<vector<int> >& mat ,int potential_celebrity){
        for(int i = 0;i<mat.size();i++){
            if(i == potential_celebrity){
                continue;
            }
            else{
                if(mat[i][potential_celebrity] != 1){  // it means i should know potential...
                    return false;
                }
            }
        }
        return true;
    }
    
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        stack<int> s;
        int n = mat.size();
        for(int i =0;i<n;i++){
            s.push(i);
        }
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(mat[a][b] == 1){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int potential_celebrity = s.top();
        if(allzero(mat,potential_celebrity) && check(mat,potential_celebrity))
            return potential_celebrity;
        return -1;
        
    }
};

int main(){
    vector<vector<int>> vec = {{0,1,0},{0,0,0},{0,1,0}};
    Solution s1;
    int celeb = s1.celebrity(vec);
    cout<<"Hmare world ke sallu bhai hai ....-:::::   "<<celeb;
    return 0;
}