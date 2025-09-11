/* NOTE - This is a very important and conceptual question */
#include<iostream>
#include<vector>
using namespace std;

    
class Node {
    public :
    int data;
    Node *next;
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
        }
};
// Function to detect a loop inside a linked list (using FLOYDS CYCLE DETECTION ALGORITHM)
bool detectloop(Node* head,Node* &fast, Node* &slow){
    while(fast != NULL && fast->next!= NULL){
        fast= fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}
// function to find the node from where loop starts
Node *beginofloop(Node* head,Node* &fast,Node* &slow){
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}
Node *removeLoop(Node *head)
{
    // Write your code here.
    Node* fast = head;
    Node* slow = head;
    // check if loop exist or not
    if(detectloop(head, fast,slow)){
        Node* start = beginofloop(head, fast, slow);
        // The logc written below will helps to remove the loop and make it as a normal singly linked list
        Node* temp = start;
        while(temp->next != start){
            temp = temp->next;
        }
        temp->next = NULL;
    }
    return head;
}
