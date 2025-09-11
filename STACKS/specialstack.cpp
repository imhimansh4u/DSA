/*  Create a stack data structure that allows operations such as push (adding an element), pop (removing the top element),
 top (retrieving the top element), and also provides a way to retrieve the minimum element in constant time.
                   */ 


// APPRROACH -->>1st (T.C. - O(1) and S.C.- O(N))
#include<iostream>
#include<stack>
#include<vector>
using namespace std;


/*
class SpecialStack {
    stack<int> main;        // main stack in which the data is inserted
    stack<int> minimum;      // another stack which keep record of the minimum element upto a perticular height...
    int min;
    public:
    int minoftwo(int a,int b){
        if(a<=b){
            return a;
        }
        else{
            return b;
        }
    }
        
    void push(int data) {
        // Implement the push() function.
        if(main.empty()){
            main.push(data);
            minimum.push(data);
        }
        else{
            main.push(data);
            int miniamongtwo = minoftwo(minimum.top(),data);
            minimum.push(miniamongtwo);  
        }
    }

    void pop() {
        // Implement the pop() function.
        if(main.empty()){
            return;
        }
        else{
            int tobepopped = main.top();
            main.pop();
            minimum.pop();
        }
    }

    int top() {
        // Implement the top() function.
        if(main.empty()){
            return -1;
        }
        else{
            return main.top();
        }
    }

    int getMin() {
        // Implement the getMin() function.
        return minimum.top();
    }  
};

*/


// APPROACH-2))  (S.C.-> O(1) and T.C.-> O(N))
class SpecialStack {
    public:
    stack<int> s;              // our main stack
    int mini ;                 // variable to keep record of the current minimun element 
    void push(int data) {
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data>=mini){
                s.push(data);
            }
            else{
                int val = 2*data - mini;
                s.push(val);
                mini = data;
            }
        }
    }

    void pop() {
        // Implement the pop() function.
        if(s.empty()){
            return;
        }
        else{
            if(s.top()>=mini){
                s.pop();
            }
            else{
                int val = 2*mini - s.top();
                s.pop();
                mini = val;
            }
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty())
            return -1;
        else{
            if(s.top()>=mini){
                return s.top();
            }
            else{
                return mini;
            }
        }
    }

    int getMin() {
        // Implement the getMin() function.
        return mini;
    }  
};
    