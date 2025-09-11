#include<iostream>
using namespace std;
// The task is to find the LCA of two nodes (LCA means Lowest common ancestor)
class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    if(root==NULL)
        return NULL;
    if(root == P || root == Q)
        return root;
    if(root->data < P->data && root->data < Q->data){
        return LCAinaBST(root->right,P,Q);
    }
    else if(root->data > P->data && root->data > Q->data){
        return LCAinaBST(root->left,P,Q);
    }
    return root;  // here when both the nodes are present in different subtrees , it means the root node is the required node ....
}
int main(){

    return 0;
}