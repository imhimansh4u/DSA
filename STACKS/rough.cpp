// #include<iostream>
// using namespace std;
// // implementation of stack uisng array..
// class stack{
//     int top;
//     int *arr;
//     int size;
//     public:
//     stack(){}  // default constructor
//     stack(int s){
//         this->size = s;
//         this->arr = new int[s];
//         this->top = -1;
//     }
//     // to check if the stack is full or not
//     bool isfull(){
//         if(top == (size-1)){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//     // push operation
//     void push(int ele){
//         if(isfull()){
//             cout<<"stack overflow";
//         }
//         else{
//             top++;
//             arr[top] = ele;
//         }
//     }
//     // peek operation
//     void peek(){
//         if(top == -1){
//             cout<<"stack underflow";
//         }
//         else
//             cout<<arr[top];
//     }
//     // pop operation 
//     void pop(int ele){
//         if(top == -1){
//             cout<<"stack underflow";
//         }
//         else{
//             top--;
//             arr[top] == ele;
//         }
//     }
// };
// // implementation of stack using linked list
// class node{
//     public:
//     int data;
//     node* next ;
//     node(int val){
//         this->data = val;
//         this->next = NULL;
//     }
// };
// class stack{
//     node* head;
//     public:
//     stack(){
//         this->head = NULL;
//     }
//     // to check if the stack is empty or not
//     bool isempty(){
//         return head == NULL;
//     }
//     // to push element in the stack
//     void push(int ele){
//         node* newnode = new node(ele);
//         // check if the memory allocation is failed
//         if(!newnode){
//             cout<<"Stack overflow";
//         }
//         else{
//             newnode->next = head;
//             head = newnode;
//         }
//     }
//     // pop operation 
//     void pop(){
        
//     }

// };


// int main(){

//     return 0;
// }
#include<iostream>
#include<stack>
using namespace std;
void sortedinsert(stack<int> &s, int x){
    // 1st base case
    if(s.empty()){
        s.push(x);
        return;
    }
    // 2nd base case
    if(s.top()<x){
        s.push(x);
        return;
    }
    int el = s.top();
    s.pop();
    sortedinsert(s,x);
    s.push(el);
}
void sortstack(stack<int> &s){
    // firstly pop out all elements
    if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();
    sortstack(s);
    // waps jate time sorted insert kr do
    sortedinsert(s,x);
}
// function to print the element of stack
void print(stack<int> &s){
    if(s.empty()){
        return;
    }
    int el = s.top();
    s.pop();
    cout<<el<<" ";
    print(s);
    s.push(el);
}

int main(){
    stack<int> s;
    s.push(11);
    s.push(22);
    s.push(37);
    s.push(1);
    s.push(15);
    print(s);
    cout<<endl;
    sortstack(s);
    print(s);
    
    return 0;
}
