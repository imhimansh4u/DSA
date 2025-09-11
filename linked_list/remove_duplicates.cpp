#include<iostream>
using namespace std;
/* TASK -- remove duplicates from a sorted doubly linked list*/

//Definition of doubly linked list:


/*
class Node {
public:
     int data;
     Node *prev;
     Node *next;
     Node() {
         this->data = 0;
         this->prev = NULL;
         this->next = NULL;
     }
     Node(int data) {
         this->data = data;
         this->prev = NULL;
         this->next = NULL;
     }
     Node (int data, Node *next, Node *prev) {
         this->data = data;
         this->prev = prev;
         this->next = next;
     }
};


Node * removeDuplicates(Node *head)
{
    if(head == NULL ){
        return NULL;
    }
    else if(head->next == NULL){
        return head;
    }
    else{
        Node* temp = head;
        Node* t = head->next;
        while(t!=NULL){
            if(temp->data == t->data){
                Node* todelete = t;
                Node* forward = t->next;
                if(todelete->next){
                    todelete->next->prev = todelete->prev;
                }
                if(todelete->prev){
                    todelete->prev->next = todelete->next;
                }
                delete todelete;
                t = forward;
            }
            else{
                temp = temp->next;
                t = t->next;
            }
        }
    }
    return head;
}

int main(){
    return 0;
}
*/

/* TASK 2--  (REMOVE DUPLICATES FROM A UNSORTED SINGLY LINKED LIST)           */  




#include<iostream>
#include<map>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int val){        // constructor to create a new node.       
            this->data = val;
            this->next = NULL;
        }
};
// APPROACH ->1))(BY THE HELP OF USING MAPPING CONCEPT)  T.C.--> O(n) and S.C. -> O(n)
/*
node* removeDuplicates(node* head){
    if(head == NULL){
        return NULL;
    }
    else if(head->next == NULL){
        return head;
    }
    else{
        node* temp = head;
        node* back = NULL;
        map<int , bool> mp;
        while(temp != NULL){
            if(mp[temp->data]){
                node* todelete = temp;
                node* forward = todelete->next;
                back->next = todelete->next;
                todelete->next = NULL;
                delete todelete;
                temp = forward;
            }
            else{
                // mp[back->data] = true;
                mp[temp->data] = true;
                back = temp;
                temp = temp->next;
            }
        }
    }
    return head;
}
*/
// APPROACH ->2 (By brute force technique --i.e. checking for each element that it is already present in the LL or not) 
// T.C -> O(n^2) ,,  S.C. -> O(1)..
node *removeDuplicates(node *head)
{
    // Write your code here
    if(head == NULL){
        return NULL;
    }
    else if(head->next == NULL){
        return head;
    }
    else{
        node* temp = head;
        while(temp != NULL){
            node* back = temp;
            node* chotatemp = temp->next;
            while(chotatemp != NULL){
                if(chotatemp->data == temp->data){
                    node* todelete = chotatemp;
                    back->next = chotatemp->next;
                    chotatemp = chotatemp->next;
                    delete todelete;
                }
                else{
                    back = chotatemp;
                    chotatemp = chotatemp->next;
                }
            }
            temp = temp->next;
        }
    }
    return head;
}
void print(node* &head){
    node* temp = head;
    while(temp != NULL){            // traversing till the last node and printing it
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    node* head = new node(1);
    head->next = new node(1);
    head->next->next = new node(3);
    head->next->next->next = new node(1);
    head->next->next->next->next = new node(1);
    head->next->next->next->next->next = new node(4);
    head->next->next->next->next->next->next = new node(4);
    head->next->next->next->next->next->next->next = new node(4);
    print(head);
    head = removeDuplicates(head);
    print(head);
    return 0;
}
 