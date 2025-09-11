/*
You have been given a binary search tree of integers with ‘N’ nodes. Your task is to convert it into a balanced BST with the minimum height possible.

A binary search tree (BST) is a binary tree data structure that has the following properties.

• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
A Balanced BST is defined as a BST, in which the height of two subtrees of every node differs no more than 1.
*/
#include<iostream>
#include<vector>
using namespace std;
template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
void InorderTraversal(TreeNode<int>* root,vector<int> &v){
    if(root==NULL)
        return;
    InorderTraversal(root->left,v);
    v.push_back(root->data);
    InorderTraversal(root->right,v);
}
TreeNode<int>* solve(vector<int> v, int s,int e){             /* We have used simple logic here  
                                                                WKT, in BST inorder traversal is in sorted order
                                                                so, we have stored it in a vector and we make mid 
                                                                element of it as the root node, and then previous to mid elements will
                                                                be in left subtree and after the mid element will be in the rightSUb tree
                                                                This will simply give us a balanced BST ..e

                                                                */
    if(s>e)
        return NULL;
    int mid = s+ (e-s)/2;
    TreeNode<int>* NewRoot =  new TreeNode<int>(v[mid]);
    NewRoot->left = solve(v,s,mid-1);
    NewRoot->right = solve(v,mid+1,e);
    return NewRoot;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> v;
    InorderTraversal(root,v);
    int startIndx = 0;
    int endIndx = v.size()-1;
    return solve(v,startIndx,endIndx);
}

int main(){

    return 0;
}