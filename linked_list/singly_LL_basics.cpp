#include<iostream>
using namespace std;
// construction of a node using class
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
// To find the length of the Linked list
    int length(node* head){
        int count = 0 ;
        node* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        } 
        return count;
    }
void insertathead(node* &head ,int data){  // you can also pass the argument as head wihtout passing refernce but without reference it will make a copy
    node* temp = new node(data); // makinng new node
    temp->next = head;   // here head is pointed on the previous node .. which now by this program becomes second node
    head = temp;      // now head is pointed on the newly inserted node
}
void insertatend(node* &head, int data){
    node* fresh = new node(data);    // making a new node and inserting data inside it 
    node* temp =  head;              // temp node pointing to head
    while(temp->next != NULL){       // traversing till end of the linked lit
        temp = temp->next;
    }                               // now temp node points on last node(tail node)
    temp->next = fresh;             
    fresh->next = NULL;             // the next of the new node(fresh) points to null , means it is tail node
}
void insertinmiddle(node* &head,int data,int pos){
    if(pos<=length(head)+1){   // checking if the pos is in range of the length ot not
        if(pos == 1){             // for the first postion 
            insertathead(head,data);
        }
        else{
            node* temp = head;     // pointer to head
            node* fresh = new node(data);    // the node to be inserted
            for(int i = 1;i<pos-1;i++){
                temp = temp->next;   // it will point temp to the prev position of the position at wich we wants to insert..
            }
            fresh->next = temp->next;  //understand by mind
            temp->next = fresh;    // understand by mind ..
        }
    }
    return;
}
void deletenode(node* &head, int position){
    // for the starting or the first position 
    if(position == 1){
        node* temp = head;
        head = head->next;
        delete temp;
    }
    // for all every other nodes  
    else{
        node* prev = head;
        for(int i = 1;i<position-1;i++){
            prev = prev->next;          // now prev will point to the previous node to the node which is to be deleted..
        }
        node* curr = prev->next;       //curr is the node present at position which is to be deleted..
        prev->next = curr->next;       // This will unlink the node .. 
        delete curr;                   //It will free up the memory associated with curr..
    }
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
    node* node1 = new node(10);
    node* head = node1;            // first node is head node
    /*                                                     note-->>
    The first node is also last node if only one node is present .. so we can also do many operations and easify our 
    fuctions (keep in mind if needed)..
     */

    //node* tail  = node1;
    insertathead(head,20);
    insertathead(head,30);
    insertathead(head,40);
    print(head);
    insertatend(head,50);
    print(head);
    insertinmiddle(head,60,1);
    print(head);
    int n = length(head);
    deletenode(head,n);
    print(head);
    return 0;
}
