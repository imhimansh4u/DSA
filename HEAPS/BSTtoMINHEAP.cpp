#include<iostream>
#include<queue> 
using namespace std;
/*Given a binary search tree which is also a complete binary tree. The problem is to convert the given BST into a Min Heap with the condition that
 all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied to 
 all the nodes, in the resultant converted Min Heap. 
*/
class Node{
    public:
    Node* left;
    Node* right;
    int data;
    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
//function to construct a tree
Node* ConstructBstTree(Node* &root,int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    if(val>root->data){
        root->right = ConstructBstTree(root->right,val);
    }
    else if(val<root->data){
        root->left = ConstructBstTree(root->left,val);
    }
    return root; 
}
// function for inorder traversal
void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL); // NULL will help us to understand that when we have to move to the next level ( It is separator ) ..
                  // here after root level 0 has ended , so added the separator   ........
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // it means that purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // it means queue has still some child nodes
                q.push(NULL); // separator added after the child node
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
// function to store inorder traversal of a BST
void inorder(Node* root,vector<int> &in){
    if(root == NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);

}
// Now function to Construct a MIN Heap from BST.. With above given Conditions 
Node* minHeap(Node* root,vector<int> &in,int &i){        // here in is the inorder traversal of that perticular BST and i is for the index
    if(root == NULL)
        return NULL;
    root->data = in[i++];
    root->left = minHeap(root->left,in,i);
    root->right = minHeap(root->right,in,i);
    return root;
}
int main(){
    Node* root = NULL;
    vector<int> input = {4,2,6,1,3,5,7};
    for(int i = 0;i<input.size();i++){
        ConstructBstTree(root,input[i]);
    }
    cout<<"Here is the Original BST"<<endl;
    LevelOrderTraversal(root);
    //inorder travesal of the BST 
    vector<int> in;
    inorder(root,in);
    int i = 0;
    minHeap(root,in,i);
    cout<<endl<<"Here is the Min heap"<<endl;
    LevelOrderTraversal(root);

    return 0;
}