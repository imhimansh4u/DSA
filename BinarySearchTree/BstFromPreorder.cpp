/*GIven a vector with preorder traversal of a bst , construct a tree in T.C. of O(n)*/
#include <bits/stdc++.h> 
using namespace std; 
    // Following is the class structure of BinaryTreeNode class for referance:
template <typename T>
class BinaryTreeNode {
   public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left){
            delete left;
        }
        if (right){
            delete right;
        }
    }
};

BinaryTreeNode<int>* solve(vector<int> &preorder,int mini,int maxi,int &i){
    if(i>=preorder.size())
        return NULL;
    if(preorder[i]<mini || preorder[i]>maxi)
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
    root->left = solve(preorder,mini,root->data,i);
    root->right = solve(preorder,root->data,maxi,i);
    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int i = 0;
    return solve(preorder,INT_MIN,INT_MAX,i);
}
int main(){
    return 0;
}