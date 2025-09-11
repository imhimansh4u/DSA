/*Given an array arr[] of n sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a 
single sorted linked list, then return the head of the merged linked list.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
class Compare{
    public:
    bool operator()(Node* A ,Node* B){
        return A->data > B->data;
    }
};
class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        priority_queue<Node*,vector<Node*>,Compare> pq;
        int n = arr.size();
        //step ->1)) insert the first element of all the LL in the mean heap 
        for(int i = 0;i<n;i++){
            if(arr[i] != NULL){
                pq.push(arr[i]);
            }
        }
        Node* head = NULL;
        Node* tail = NULL;
        // Now for the rest of the elements
        while(!pq.empty()){
            Node* top = pq.top();
            pq.pop();
            if(top->next){
                pq.push(top->next);
            }
            if(head == NULL){   // when the list is empty
                head = top;
                tail = top;
            }
            else{       // insert at end logic  
                tail->next = top;
                tail = tail->next;
            }
        }
        return head;
    }
};
int main(){

    return 0;
}