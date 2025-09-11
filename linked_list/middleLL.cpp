#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
        node(int val){        // constructor to create a new node.
            this->data = val;
            this->next = NULL;
        }
        ~node(){                // This destructor will help to remove mem0ry associated with the any node  .
            int value = this->data;
            // memory free
            if(this->next != NULL){
                this->next = NULL;          // This will free any address stored in (this->next )
                delete next; 
            }
            cout<<"Node with value of "<<this->data<<" is deleted .. "<<endl;
        }
};
void insertathead(node* &head ,int data){  // you can also pass the argument as head wihtout passing refernce but without reference it will make a copy
    node* temp = new node(data); // makinng new node
    temp->next = head;   // here head is pointed on the previous node .. which now by this program becomes second node
    head = temp;      // now head is pointed on the newly inserted node
}
void print(node* &head){
    node* temp = head;
    while(temp != NULL){            // traversing till the last node and printing it
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

node* findmiddle(node* head){
    node* fast = head->next;
    node* slow = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main(){
    node* node1 = new node(10);
    node* head = node1;
    insertathead(head,9);
    insertathead(head,8);
    insertathead(head,7);
    insertathead(head,6);
    insertathead(head,5);
    insertathead(head,4);
    insertathead(head,3);
    print(head);
    node* middle_element = findmiddle(head);
    cout<<middle_element->data;
    return 0;
}