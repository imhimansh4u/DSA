#include<iostream>
using namespace std;
class Node{
    public: 
    Node* left;
    Node* right;
    int data;
    Node(int val){
        this->left = NULL;
        this->right = NULL;
        this->data = val;
    }
};
// Function to find the minimum value 
Node* Minval(Node* root){
    if(root == NULL){
        return NULL;
    }
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}
// Function to find the maximum value 
Node* Maxval(Node* root){
    if(root == NULL){
        return NULL;
    }
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}
// Now the main function to delete a Node with data val from a bst
Node* DeleteFromBST(Node* root, int val){
    //base case
    if(root==NULL){
        return root;
    }
    if(root->data == val){
        // in this Three cases are possible 
        //1.) the root has 0 child
        if(root->left == NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //2.) only one child is present 
        //2.1) left subchild is present
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root->left;
            return temp;
            
        }
        //2.2) right subchild is present
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root->right;
            return temp;
        }
        /*                                            Both the childs are present 
        In this case Two possible solution are :::--->>>
        1.) a) copy the smallest node from the rightsub tree in the root(say mini)
            b) call the delete funtion in the rightsub tree with mini value to be deleted 
        */
       if(root->left!=NULL && root->right!=NULL){
           int mini = Minval(root->right)->data;
           root->data = mini ;
           root->right = DeleteFromBST(root->right,mini);
           return root;
       }
       /*
       2.) a) copy the largest node from the leftsub tree in the root(say maxi)
            b) call the delete funtion in the leftsub tree with maxi value to be deleted */
        if(root->left!=NULL && root->right!=NULL){
           int maxi = Maxval(root->left)->data;
           root->data = maxi ;
           root->left = DeleteFromBST(root->left,maxi);
           return root;
       }
    }
    else if(root->data > val){
        root->left = DeleteFromBST(root->left,val);
        return root;
    }
    else{
        root->right = DeleteFromBST(root->right,val);
        return root;
    }
}


int main(){

    return 0;
}