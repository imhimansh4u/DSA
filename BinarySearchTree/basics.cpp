/* Start and basics of BST
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Node{
    public:
        int data ;
        Node* left;
        Node* right;
        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};
// Function to insert data in a BST ..
Node* insertIntoBST(Node* root,int d ){
    // base case
    if(root == NULL){
        root = new Node(d );
        return root;
    }
    if(d > root->data){
        // right part me insert krna hai
        root->right = insertIntoBST(root->right,d);
    }
    else if(d < root->data){
        // left part me insert krna hai
        root->left = insertIntoBST(root->left,d);
    }
    return root;
}
// Function to take input for the BST
// please note that all the entries should be unique 
void takeInput(Node* &root){
    int data;
    cin>>data;
    // here we will enter -1 to remark the stopage of the entrie
    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}
// Level order Traversal to traverse the BST
void levelOrder(Node* &root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}
// inorder traversal of the BST
void Inorder(Node* &root){
    if(root == NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void PreOrderTraversal(Node *root)
{ // NLR
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(Node *root)
{ // LRN
    if (root == NULL)
    {
        return;
    }
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}
// To find the minimum value in a given BST
int minvalue(Node* root){
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp->data;
}
// To find the maximum value in a given BST
int maxvalue(Node* root){
    Node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp->data;
}
int main(){
    Node* root = NULL;
    cout<<"Enter the entries of the Bst to create it"<<endl;
    takeInput(root);
    levelOrder(root);
    cout<<endl<<"inorder traversal"<<endl;
    Inorder(root);          // Important property -->> Inorder traversal of a BST is always in sorted order in ascending order....
    cout<<endl<<"preorder traversal"<<endl;
    PreOrderTraversal(root);
    cout<<endl<<"postorder traversal"<<endl;
    PostOrderTraversal(root);
    cout<<endl<<"The minimum value in the given BST is  :: "<<minvalue(root);
    cout<<endl<<"The maximum value in the given BST is  :: "<<maxvalue(root);
    return 0;
}