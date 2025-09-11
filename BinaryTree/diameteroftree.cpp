/*TASK->>     ((IMPORTANT*))
Given a binary tree, the diameter (also known as the width) is defined as the number of edges on the longest path between two leaf
nodes in the tree. This path may or may not pass through the root. Your task is to find the diameter of the tree.
*/
#include<iostream>
#include<algorithm>
using namespace std;

// Tree node structure  used in the program

class Node
{ // Node for a tree
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
// APPROACH 1))   Here T.C. = O(N^2) , where N is the no. of nodes present in that tree (Because we are traverseing all nodes twice
// once for the diameter function call and other for the height function call)
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node* root){
        if(root == NULL){
            return -1;
        }
        int lh = height(root->left);     // calculate the height of the left subtree   .
        int rh = height(root->right);    // calculate the height of the right subtree  .
        return max(lh,rh)+1;       
    }
    int diameter(Node* root) {
        // Your code here
        if(root == NULL){
            return 0;
        }
        int opt1 = diameter(root->left);   // It means either we could find the longest path on left of the root
        int opt2 = diameter(root->right);   // or we can find the longest path on the right of the root
        int opt3 = height(root->left) + height(root->right) + 2;  // isko dry run krlena smjh aa jaega kyu aisa kr rhe hai
        int ans = max(opt2 , max(opt1,opt3));      // tino me se jisse sbse jada longest path aega wo answer hoga
        return ans; 
    }
};
// APPROACH 2)) In last approach we got time complexity of O(n^2), So now we will make a function that will traverse through the
// tree but only one time to a one node and make a function that will return both height and diameter at one time..
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    pair<int , int> diameterfast(Node* root){
        if(root == NULL){
            pair<int , int> p;
            p.first = 0;   // In first part we will store diameter 
            p.second = -1;  // In second part we will store height
            return p;
        }
        // Now for the main calculation
        pair<int,int> left = diameterfast(root->left);
        pair<int,int> right = diameterfast(root->right);
        // Now checkng all three options for diamter calculation
        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second +2;   // basically checking that the sum of
                        //left height of the root and right side of the height of the root..
        
        pair<int,int> ans;
        ans.first = max(opt1,max(opt2,opt3));
        ans.second = max(left.second , right.second) + 1;
        return ans;
    }
    int diameter(Node* root) {
        // Your code here
        pair<int,int> pr = diameterfast(root);
        return pr.first;
    }
};
int main(){

    return 0;
}