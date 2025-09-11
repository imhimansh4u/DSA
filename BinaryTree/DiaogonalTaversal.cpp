/*NOTE-->>
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child 
over the right child when traversing. Do not include leaf nodes in this section.

Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse 
order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was 
already included in the left boundary.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 
*/
#include<iostream>
#include<vector>
// Node data structure for the tree...
class Node{
    public:
    int data;
    Node* left, * right;
}; 

class Solution {
  public:
  // function to append the nodes present on the left boundary 
    void leftOrderTraversal(Node* root , vector<int> &ans){
        if(root == NULL){
            return;
        }
        // for leaf nodes
        if(root->left == NULL && root->right  == NULL){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            leftOrderTraversal(root->left,ans);
        }
        else{
            leftOrderTraversal(root->right,ans);
        }
    }
    // function to append the nodes present on the leaf boundary
    void leafTraversal(Node* root , vector<int> &ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
        }
        if(root->left){
            leafTraversal(root->left,ans);
        }
        if(root->right){
            leafTraversal(root->right,ans);
        }
        
    }
    // function to append on the right boundary 
    void rightOrderTraversal(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        // for leaf nodes
        if(root->left == NULL && root->right  == NULL){
            return;
        }
        if(root->right){
            rightOrderTraversal(root->right,ans);
        }
        else{
            rightOrderTraversal(root->left,ans);
        }
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        // here we are going to break the que. into three parts
        /*1.) print the left part     (up to down)
         2.) print the leaf nodes   (left to right)
         3.) print the right nodes (in down to up order)
        */
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        ans.push_back(root->data);
        // firstly left part ko push kr do
        leftOrderTraversal(root->left,ans);
        // Now leaf nodes ko traverse krke push kr lo (from left to right)
        // firstly left subtree me leaf nodes
        leafTraversal(root->left,ans);
        // Now right subtree me leaf nodes
        leafTraversal(root->right,ans);
        // Now right part ko push kr do
        rightOrderTraversal(root->right,ans);
        return ans;
    }
};
using namespace std;

int main(){

    return 0;
}