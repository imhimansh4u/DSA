/*You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

A binary tree is considered a max-heap if it satisfies the following conditions:

Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
Max-Heap Property: The value of each node is greater than or equal to the values of its children.
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;           // T.C. -> O(N) and S.C. -> O(N)
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution {
  public:
    //function to count total nodes
    int Count(Node* tree){
        if(!tree)
            return 0;
        int left = Count(tree->left);
        int right = Count(tree->right);
        return left + right + 1;
    }
    // function to check CBT && its other property 
    bool isCBT(struct Node* tree,int TotalNodes,int i){
        if(!tree)
            return true;
        if(i>=TotalNodes)
            return false;
        bool left = isCBT(tree->left,TotalNodes,2*i+1);
        bool right = isCBT(tree->right,TotalNodes,2*i+2);
        bool cond1 = true;
        bool cond2 = true;
        if(tree->left){
            if(tree->left->data > tree->data)
                cond1 = false;
        }
        if(tree->right){
            if(tree->right->data > tree->data)
                cond2 = false;
        }
        return cond1 && cond2 && left && right;  // It is the correct most Code 
        
    }
    bool isHeap(struct Node* tree) {
        // code here
        return isCBT(tree,Count(tree),0);
    }
};

int main(){

    return 0;
}