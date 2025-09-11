#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* prev;
        node* next;
    // constructor to create a new node and inititalise it.
    node(int val){
        this->data = val;
        this->prev = NULL;
        this->next = NULL;
    }
};
void insertathead(node* &head, int data) {
    node* temp = new node(data);
    temp->next = head;
    if (head != NULL) { // Check if the list is not empty
        head->prev = temp; // Link the old head to the new node
    }
    head = temp; // Update head to the new node
}
void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
// APPRAOCH 1-> ITERATIVE APPROACH
/*
void reverseit(node* &head){
    node* before = NULL;
    node* curr = head;
    while(curr != NULL){
        node* forward = curr->next;
        curr->next = before;
        curr->prev = forward;
        before = curr;
        curr = forward;
    }
    head = before;
}
*/

// APPROACH->2) RECURSIVE APPROACH
void reversal(node* &head,node* before,node* curr){
    // base case
    if(curr == NULL){
        head = before;
        return;
    }
    node* forward = curr-> next;
    curr->next = before;
    curr->prev = forward;
    reversal(head,curr,forward);
}
void reverseit(node* &head){
    node* before = NULL;
    node* curr = head;
    reversal(head,before,curr);
}
int main(){
    node* node1 = new node(11);
    node* head = node1;
    insertathead(head,10);
    insertathead(head,9);
    insertathead(head,8);
    insertathead(head,7);
    insertathead(head,6);
    insertathead(head,5);
    print(head);
    cout<<"After reversal :: "<<endl;
    reverseit(head);
    print(head);
    return 0;
}