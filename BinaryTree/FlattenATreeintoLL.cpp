#include<iostream>
using namespace std;

//User function Template for C++
class Node{
    public:
    Node* left;
    Node* right;
    int data;
    Node(int val){
        left =NULL ;
        right = NULL;
        data = val;
    }
};
// BELOW IS THE RECURSIVE APPROACH
class Solution
{
    public:
    void solve(Node* root , Node* &prev){
        if(root == NULL)
            return;
        solve(root->right,prev);
        solve(root->left,prev);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
    void flatten(Node *root)
    {
        //code here
        Node* prev = NULL;
        solve(root,prev);
    }
};
// BELOW IS BY HELP OF MORRIS TRAVERSAL

//User function Template for C++

class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        Node* curr = root;
        while(curr){
            if(curr->left){
                Node* prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev -> right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
int main(){

    return 0;
}