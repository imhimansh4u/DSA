#include <bits/stdc++.h>
using namespace std;
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
class Solution {
  public:
    /*1st APPROACH)->(store the inorder traversal of both the nodes in vector , and then merge two 
    sorted arrays is the question(OR if asked to construct the tree also then you know to construct a
    tree using the inorder traversal of a tree ))-->T.C.->O(m+n) and S.C. -> O(m+n)  ..
    */
    
    /* 2nd approach)->step 1 -> flatten the both trees in linked list
     step 2->> merge two sorted linked list
     step 3->> construct a tree from a linked list
    */
    // step 1->)
    void flatten(Node* &root, Node* &Dummyhead){   // here jsut for prctice we are converting it in DLL 
        if(root == NULL)
            return;
        flatten(root->right,Dummyhead);
        root->right = Dummyhead;
        if(Dummyhead)
            Dummyhead->left = root;
        Dummyhead = root;
        flatten(root->left,Dummyhead);
    }
    // Now function to merge two sorted LINKed list into a new sorted Linked list (here Doubly)
    Node* mergeit(Node* root1 , Node* root2){
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        Node* t1 = root1;
        Node* t2 = root2;
        while(t1 && t2){
            if(t1->data < t2->data){
                temp->right = t1;
                t1->left = temp;
                temp = temp->right;
                t1 = t1->right;
            }
            else{
                temp->right = t2;
                t2->left = temp;
                temp = temp->right;
                t2 = t2->right;
            }
        }
        while(t1){
            temp->right = t1;
            t1->left = temp;
            temp = temp->right;
            t1 = t1->right;
        }
        while(t2){
            temp->right = t2;
            t2->left = temp;
            temp = temp->right;
            t2 = t2->right;
        }
        Node* head = dummy->right;
        if(head)
            head->left = NULL;
        delete dummy;
        return head;
    }
    // firstly count total no. of nodes
    int countNodes(Node* head){
        Node* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->right;
        }
        return count;
    }
    // Step 3-> Convert A DLL into a Binary Search Tree
    Node* convertDLLtoTree(Node* &head,int n){
        if(n<=0 || head == NULL)
            return NULL;
        Node* leftside = convertDLLtoTree(head,n/2);
        Node* temphead = head;
        if (!temphead) return NULL;
        head = head->right;
        temphead->left = leftside;
        temphead->right = convertDLLtoTree(head,n-(n/2)-1);
        return temphead;
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        //step1) 
        Node* d1 = NULL;
        Node* d2 = NULL;    
        flatten(root1,d1);
        flatten(root2,d2);
        //step2)
        Node* Head = NULL;
        Head = mergeit(d1,d2);
        Head = convertDLLtoTree(Head,countNodes(Head));
    }
};
int main(){
    return 0;
}