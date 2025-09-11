/*TASK -- >> Given a binary tree, determine if it is height-balanced. A binary tree is considered height-balanced if the absolute
difference in heights of the left and right subtrees is at most 1 for every node in the tree.
*/
#include<iostream>
#include<algorithm>

using namespace std;
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
// APPROACH 1-->> BRUTE FORCE .. T.C. -> O(n^2).. and S.C -> O(h) where,
// h is the height of the tree(because worst case me h nodes call stack me pde ho skte hai)
class Solution {
  public:
    // Function to calculate the height of a tree
    int height(Node* root){
        if(root == NULL){
            return -1;
        }
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) +1;
    }
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node* root) {
        // Code here
        if(root == NULL){
            return true;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(height(root->left) - height(root->right)) <= 1;
        // 
        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }
    }
};
// APPROACH 2->>T.C.-> o(N)


class Solution2 {
  public:
    // Function to check whether a binary tree is balanced or not.
    pair<bool,int> isBalancedhelp(Node* root) {
        // Code here
        if(root == NULL){
            pair<bool,int> p;
            p.first = true;
            p.second = -1;
            return p;
        }
        pair<bool,int> left = isBalancedhelp(root->left);   // check for the left subtree
        pair<bool,int> right = isBalancedhelp(root->right); // check for the right subtree
        bool diff  = abs(left.second - right.second) <= 1;  
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) +1;
        if(left.first && right.first && diff){   // check if the left and right subpart is balanced and the abs(differernce)<=1..are true 
            ans.first = true;
            return ans;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(Node* root) {
        // Code here
        pair<bool,int> pr = isBalancedhelp(root);
        return pr.first;
    }
};


int main(){

    return 0;
}