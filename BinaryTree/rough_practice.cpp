// /*
// #include<iostream>
// #include<queue>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int data){
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// Node* BuildTree(Node* &root){
//     int data;
//     cout<<"Enter the data :: ";
//     cin>>data;
//     root = new Node(data);
//     if(data == -1){        // consider that for data = -1 , it is demostrating NULL Node.
//         return NULL;
//     }
//     cout<<"Enter the data to be inserted in the left of "<< root->data <<endl;
//     root->left = BuildTree(root->left);
//     cout<<"Enter the data to be inserted in the right of "<< root->data <<endl;
//     root->right = BuildTree(root->right);
//     return root;
// }

// // inorder traversal -------->>>>>> (LNR)
// void inOrderTraversal(Node* &root){
//     if(root == NULL){
//         return;
//     }
//     inOrderTraversal(root->left);
//     cout<<root->data<<" ";
//     inOrderTraversal(root->right);
// }
// // preorder traversal
// void preOrderTraversal(Node* &root){
//     if(root == NULL){
//         return;
//     }
//     cout<<root->data<<" ";
//     preOrderTraversal(root->left);
//     preOrderTraversal(root->right);
// }
// void postOrderTraversal(Node* &root){
//     if(root == NULL){
//         return;
//     }
//     postOrderTraversal(root->left);
//     postOrderTraversal(root->right);
//     cout<<root->data<<" ";
// }
// // Level order traversal
// void levelOrderTraversal(Node* &root){
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);   // separator
//     while(!q.empty()){
//         Node* temp = q.front();
//         q.pop();
//         if(temp == NULL){
//             cout<<endl;
//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         }
//         else{
//             cout<<temp->data<<" ";
//             if(temp->left){
//             q.push(temp->left);
//             }
//             if(temp->right){
//             q.push(temp->right);
//             }
//         } 
//     }
// }

// int main(){
//     Node* root = NULL;
//     BuildTree(root);
//     cout<<endl;
//     inOrderTraversal(root);
//     cout<<endl;
//     preOrderTraversal(root);
//     cout<<endl;
//     postOrderTraversal(root);
//     cout<<endl;
//     levelOrderTraversal(root);
//     return 0;
// }
// // 1 2 -1 -1 3 -1 -1   -->> sample data
// */
// #include<iostream>
// #include<queue>

// using namespace std;
// // structure of a tree
// class Node{
//     public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int val){
//         this->data = val;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// // buuilding a tree
// Node* BuildTree(Node* &root){
//     int data;
//     cout<<"Enter the data :: ";
//     cin>>data;
//     if(data == -1){
//         return NULL;
//     }
//     root = new Node(data); 
//     // Now left part ka input lo
//     cout<<"Enter the data to be inserted in the left of "<< data <<endl;
//     root->left = BuildTree(root->left);
//     cout<<"Enter the data to be inserted in the right of "<< data << endl;
//     root->right = BuildTree(root->right);
//     return root;

// }

// // Level order Traversal
// void LevelOrderTraversal(Node* &root){
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);    // it will tell us about the NULL point..
//     while(!q.empty()){
//         Node* temp = q.front();
//         q.pop();
//         if(temp == NULL){
//             cout<<endl;
//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         }
//         else{
//             cout<<temp->data<<" ";
//             // Now check if the left part of the Node exists or not
//             if(temp->left){
//                 q.push(temp->left);
//             }
//             if(temp->right){
//                 q.push(temp->right);
//             }
//         }
//     }
// }
// // inorder traversal
// void InorderTraversal(Node* &root){
//     if(root == NULL){
//         return;
//     }
//     // left part traverse kro
//     InorderTraversal(root->left);
//     cout<<root->data<<" ";
//     InorderTraversal(root->right);
// }
// // Build a tree using level Order Traversal
// Node* BuildTreeLevel(Node* &root){
//     queue<Node*> q;
//     int data;
//     cout<<"Enter the data "<<endl;
//     cin>>data;
//     root = new Node(data);
//     q.push(root);
//     while(!q.empty()){
//         Node* temp  = q.front();
//         q.pop();
//         // Now left part
//         int LeftData;
//         cout<<"Enter the left part for "<<temp->data<<" ";
//         cin>>LeftData;
//         if(LeftData != -1){
//             temp->left = new Node(LeftData);
//             q.push(temp->left);
//         }
//         int rightData;
//         cout<<"Enter the right part for "<<temp->data<<" ";
//         cin>>rightData;
//         if(rightData != -1){
//             temp->right = new Node(rightData);
//             q.push(temp->right);
//         }
//     }
//     return root;
// }

// int main(){
//     Node* root = NULL ;
//     BuildTreeLevel(root);
//     cout<<endl;
//     LevelOrderTraversal(root);
//     cout<<"Now inorder traversal :: "<<endl;
//     InorderTraversal(root);
//     return 0;
// }
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class node
{ // Node for a tree
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

bool Solve(node* root, node* el,vector<int> &ans){
    if(!root) return false;
    bool left = Solve(root->left,el,ans);
    bool right = Solve(root->right,el,ans);
    if(root == el){
        return true;
    }
    if(left || right){
        ans.push_back(root->data);
        return true;
    }
    return false;
}