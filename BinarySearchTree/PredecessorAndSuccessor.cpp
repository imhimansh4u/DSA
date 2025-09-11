/*You are given root node of the BST and the key node of the tree. You need to find the in-order successor and predecessor of a given key. 
If either predecessor or successor is not found, then set it to NULL.
*/
#include<iostream>
using namespace std;
// for the srtucutre of the tree
class Node{
    public:
        int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
class Solution
{
    public:
    void predcessor(Node* root,Node* &pre,int data){
        pre = NULL;
        while(root!=NULL){
            if(root->key <data){
                pre = root;
                root = root->right;
            }
            else if(root->key >= data){
                root = root->left;
            }
        }
    }
    void Successor(Node* root,Node* &suc, int data) {
        // Your code here
        suc = NULL;
        while(root!=NULL){
            if(root->key > data){
                // It means go in the right part of the BST , to search for the possible answer
                suc = root;
                root = root->left;
            }
            else if(root->key <= data){
                root = root->right;
            }
        }
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int data)
    {
        // Your code goes here
        predcessor(root,pre,data);
        Successor(root,suc,data);
    }
};

int main(){

    return 0;
}