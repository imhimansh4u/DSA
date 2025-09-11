// NOTE -->> VERY VERY MAST QUE..
#include <bits/stdc++.h>
using namespace std;

// Following is the linked list node structure.

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data)
    {
        next = NULL;
        this->data = data;
    }
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};
//APPROACH-1) THIS APPROACH EXTRA SPACE(NOT EFFICIENT)
/*
Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    Node<int> *t1 = first;
    Node<int> *t2 = second;
    Node<int> *temphead = new Node<int>(-2);
    Node<int> *temp = temphead;
    while (t1 != NULL && t2 != NULL)
    {
        if ((t1->data) < (t2->data))
        {
            Node<int> *temporary = new Node<int>(t1->data);
            temp->next = temporary;
            temp = temporary;
            t1 = t1->next;
        }
        else if ((t1->data) > (t2->data))
        {
            Node<int> *temporary = new Node<int>(t2->data);
            temp->next = temporary;
            temp = temporary;
            t2 = t2->next;
        }
        else
        {
            Node<int> *temporary = new Node<int>(t1->data);
            temp->next = temporary;
            temp = temporary;
            t1 = t1->next;
            temporary = new Node<int>(t2->data);
            temp->next = temporary;
            temp = temporary;
            t2 = t2->next;
        }
    }
    while (t1 != NULL)
    {
        Node<int> *temporary = new Node<int>(t1->data);
        temp->next = temporary;
        temp = temporary;
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        Node<int> *temporary = new Node<int>(t2->data);
        temp->next = temporary;
        temp = temporary;
        t2 = t2->next;
    }
    temp->next = NULL;
    Node<int> *head = temphead->next;
    delete temphead;
    return head;
}*/

// APPROACH 2) -- Without creating new nodes therfore .. with constand space complexity  .. O(1).

// through below function we will update the first LL by merging the second LL into it   ....
Node<int>* solve(Node<int>* first, Node<int>* second){
    if(first->next == NULL){    // if only one element is present in the first LL
        first->next = second;
        return first;
    }
    Node<int>* prev = first;     // prev ptr will point to head of the LL
    Node<int>* t1 = prev->next;  // t1 ptr will point to the next node of the prev function
    Node<int>* t2 = second;      // firstly it points to the head of the second LL....
    while(t1!=NULL && t2!= NULL){
        if((t2->data) >= (prev->data) && (t2->data)<= (t1->data)){   // condition after which we
                                                        //will insert element in the first LL
            Node<int>* forward = t2->next;       // to keep the record of elements in second LL
            t2->next = t1;  // below two lines will link the node of the second LL to first
            prev->next = t2;
            prev = prev->next;      //update the pointers.
            t2 = forward;
        }
        else{               // if the element of the second LL doesn't fit between prev and t1
            prev = t1;
            t1 = t1->next;
            if(t1 == NULL){    // means prev will now point to the last element of the first LL
                prev->next = t2;
                return first;
            }
        }
    }
    return first;
}

Node<int>* sortTwoLists(Node<int>* &first, Node<int>* &second)
{
    // Write your code here.
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;
    if(first->data <= second->data){  // the LL whose starting element is smaller will be
                                     // considered as first in the solve function and usi LL
                                     // ko hm update krenge jisme dono ke elements ek sath aa 
                                     //jae
        return solve(first,second);   
    }
    else{
        return solve(second,first);
    }
}
// function to print a linked list
void print(Node<int>* &head){
    Node<int>* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    // the first linked list
    Node<int>* first = new Node<int>(1);
    first->next = new Node<int>(3);
    first->next->next = new Node<int>(7);
    first->next->next->next = new Node<int>(10);
    // the second linked list
    Node<int>* second = new Node<int>(5);
    second->next = new Node<int>(8);
    second->next->next = new Node<int>(9);
    second->next->next->next = new Node<int>(78);
    second->next->next->next->next = new Node<int>(100);
    // calling the function
    cout<<"The first linked list is:: "<<endl;
    print(first);
    cout<<"The second linked list is:: "<<endl;
    print(second);

    sortTwoLists(first,second);
    cout<<"Now the LL after merging is :: "<<endl;
    print(first);
    return 0;
}