/* TASK -- Reverse a linked list in a group of (k)*/
#include<iostream>
using namespace std;

//Definition for singly-linked list.
class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

int getlength(Node* head){
    if(head == NULL){
        return 0;
    }
    else{
        Node* temp  = head;
        int count = 1;
        while (temp->next != NULL) {
             count++;
             temp = temp->next;
        }
        return count;
    }
}

Node* kReverse(Node* head, int k) {
    // base case
    if(head == NULL){
        return NULL;
    }
    // ek case slove karo
    if(getlength(head)< k){
        return head;
    }
    int count = 0;
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    while(curr  != NULL && count < k){
       forward = curr->next;
       curr->next = prev;
       prev = curr;
       curr = forward;
       count++;
    }
    // recursion se age ka case solve kardo
    if(forward != NULL){
        head->next = kReverse(forward,k);
    }
    //return kara-do
    return prev;
}