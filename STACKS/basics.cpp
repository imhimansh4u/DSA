// firstly implementation with the help of stl(standard tempelate library)
// It is not recommended (By sir Himanshu singh)
/*
#include <iostream>
#include <stack>
using namespace std;

// Below is the function to print the elements of a stack from top to bottom         .. T.C.-> (O(n)) && S.C. -> (O(n)) where n is the
// no. of elements in the stack..
void print(stack<int> s)
{
    // if list is empty(base case)
    if(s.empty()){
        return;
    }
    // extract the top element
    int x = s.top();
    // pop the top element
    s.pop();
    // print the extracted top element
    cout<<x<<" ";
    // recursive call to print the rest of elements
    print(s);
    // after printing now push the element back into the stack.
    s.push(x);
}
int main()
{
    stack<int> s;
    s.push(3);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(5);
    s.push(88);
    s.push(45);
    print(s);
    cout<<endl;
    s.pop();
    print(s);
    cout<<endl;
    cout<<s.top()<<endl;
    print(s);
    cout<<endl;
    cout<<s.empty();
    return 0;
}
*/
// Implentation of Stack using array
/*
#include<iostream>
using namespace std;

class stack{
    int top ;          // top of the stack....
    int *arr;          // array in which stack is to be implemented....
    int size;          // size of the array....
    public:
        stack(){}            // default constructor
        stack(int size){ 
            this->size = size;
            arr = new int[size];          // declaring an array dynamically.
            top = -1;
        }
        // to check if the stack is full or not
        bool isfull(){
            if(top < size-1){
                return false;
            }
            return true;
        }
        // Push operation
        void push(int element){
            if(isfull()){
                cout<<" stack Overflow :: "<<endl;
            }
            else{
                top++;
                arr[top] = element;
            }
        }
        // pop operation
        void pop(){
            if(top>=0){
                top--;
            }
            else{
                cout<<"stack underflow"<<endl;
            }
        }
        //peek
        int peek(){
            if(top>=0 && top<size){
                return arr[top];
            }
            else{
                cout<<"stack is empty"<<endl;
                return -1;
            }
        }
        // function to check if the stack is empty or not 
        bool isempty(){
            if(top == -1){
                return true;
            }
            return false;
        }
};

int main(){
    stack s(5);
    s.push(2);
    s.push(3);
    s.push(5);
    s.push(7);
    s.push(8);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.isempty();
    return 0;
}
*/

// Now implementation of stack using linked list
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
};

class stack{
    private:
        node* head;
    public:
        // constructor
        stack(){
            this->head = NULL;
        }
        // to check if the stack is empty or not
        bool isempty(){
            return head == NULL;
        }
        // push operation
        void push(int data){
            // make a new node which is to be inserted
            node* new_node = new node(data);
            // check if the memory allocation of the new_node is failed
            if(!new_node){
                cout<<"Stack overflow"<<endl;
            }
            new_node->next = head;
            head = new_node;
        }
        // pop operation
        void pop(){
            // check if the LL has some elements or not
            if(this->isempty()){
                cout<<"Stack underflow"<<endl;
            }
            else{
                node* tobe_popped = head;
                head = head->next;
                delete tobe_popped;
            }
        }
        // to seek 
        int peek(){
            if(head != NULL){
                return head->data;
            }
            else{
                cout<<"Stack is empty"<<endl;
                return INT_MIN;
            }
        }

};

int main(){
    // create a object
    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.pop();
    cout<<s1.peek()<<endl;
    bool q = s1.isempty();
    if(q){
        cout<<"Yes the stack is empty "<<endl;
    }
    else{
        cout<<"Stack has still some elements in it"<<endl;
    }
    return 0;
}