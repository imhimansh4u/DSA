/*         
                Task -- Reverse a singly linked list(We have to only return the head of new node)
                                                                                                              */
//APPROACH-(1)-- (iterative approach..)

#include <bits/stdc++.h>
using namespace std;


//Following is the class structure of the LinkedListNode class:
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
/*
LinkedListNode<int>* reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head == NULL || head->next == NULL){        // if the list contains 1 or 2 elements ....
        return head;
    }
    LinkedListNode<int>* prev = NULL;      // creating a previous pointer at which the current pointer will point
                                          // in order to reverse the LL....
    LinkedListNode<int>* curr = head;    // wo particular node jisko hm prev pe point krenge
    while(curr != NULL){                   
        LinkedListNode<int>* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;           // in last prev wala hi last node ko point krega .. jo ki hmara new head hoga..
}

*/

// APPROACH 2--)) (RECURSIVE APPROACH)
void reverse(LinkedListNode<int>* &head,LinkedListNode<int>* prev, LinkedListNode<int>* curr){
    
    if(curr == NULL){
        head = prev;
        return;
    }
    LinkedListNode<int>* temp = curr->next; // temp helps us to stay accessed to the next part of LL..
    curr->next = prev;
    reverse(head,curr, temp);
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head == NULL || head->next == NULL){
        return head;
    }
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    reverse(head,prev,curr);
    return head;
}
// APPRAOCH 3 (ANOTHER RECURSION METHOD)
/*In this method*/