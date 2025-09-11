/*Construct Tree from Inorder & Preorder*/

/*Given two arrays representing the inorder and preorder traversals of a binary tree,
construct the tree and return the root node of the constructed tree.
*/
#include<iostream>
#include<vector>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution {
  public:
    // function to find the position of the root element in the inoreder traversal
    int findposition(vector<int> inorder,int target){
        for(int i = 0;i<inorder.size();i++){
            if(inorder[i] == target)
                return i;
        }
        return -1;
    }
    // in the below function the startindx and endindx is for inoreder traversal graph 
    Node* solve(vector<int> &inorder, vector<int> &preorder,int &index,int startindx,int endindx,int n){
        if(index>=n || startindx>endindx){
            return NULL;
        }
        int element = preorder[index];
        index++;
        Node* root = new Node(element);
        int position = findposition(inorder,element); // this will find the position of the root element in the inorder traversal 
        // root ke left and right me call maar do ab 
        root->left= solve(inorder,preorder,index,startindx,position-1,n);
        root->right = solve(inorder,preorder,index,position+1,endindx,n);
        return root;
    }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int n = preorder.size();
        int index = 0; // it will track the root element in the preorder traversal vector    
        Node* ans = solve(inorder,preorder,index,0,n-1,n);
        return ans;
    }
};
int main(){

    return 0;
}