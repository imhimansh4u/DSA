/*
#include<iostream>
#include<deque>
using namespace std;
// Below is the STL code for Deque

int main(){
    // there are various operation . you can read it and understand it.
    deque<int> dq;
    dq.push_front(12);
    dq.push_back(13);
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    dq.push_front(15);
    dq.push_front(18);
    dq.pop_back();
    dq.push_back(13);
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    dq.pop_front();
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    bool ans = dq.empty();
    if(ans)
        cout<<"The Deque is currently empty"<<endl;
    else
        cout<<"The Deque is not empty "<<endl;
    
    return 0;
}
*/
// Implementation of Deque by the help of an array.
#include <bits/stdc++.h> 
using namespace std;
class Deque
{
    int front;
    int rear;
    int *arr;     // deque will be implemented in this  .... 
    int size;   // size of the array 
public:
    // Initialize your data structure.

    Deque(int n)
    {
        // Write your code here.
        size = n;
        front = rear = -1;
        arr = new int[size];
    }
     // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front == -1)
            return true;
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if((front == 0 && rear == size-1) || (rear == front-1))
            return true;
        return false;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if((front == 0 && rear == size-1) || (rear == (front-1))){
            return false;   // it means that the deque is full
        }
        else if(front == -1){   // it means the deque is empty and first element is inserted ..
            front = 0;
            rear = 0;
            arr[front] = x;
            return true;
        }
        else if(front == 0 && rear != size-1){  // if front is at 0 index then in push_front ,
                                                // now done from (size-1) index
            front = size-1;
            arr[front] = x;
            return true;
        }
        else{
            front--;
            arr[front] = x;
            return true;
        }
    }
    

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if(isFull()){
            return false;
        }
        else if(front == -1){   // already empty
            front = rear = 0;
            arr[front] = x;
            return true;
        }
        else if(rear == size-1 && front!=0){
            rear = 0;
            arr[rear] = x;
            return true;
        }
        else{
            rear++;
            arr[rear] = x;
            return true;
        }
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        int ans  = arr[front];
        if(isEmpty()){
            return -1;
        }
        else if(front == rear){  // single element is present ..
            front = rear = -1;
        }
        else if(front == size-1){  // maintaing the circular condition  ..
            front = 0;
        }
        else{
            front++;
        }
        return ans;
        
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        int ans = arr[rear];
        if(front == -1){
            return -1;
        }
        else if(front == rear){   // if single element is present....
            front = rear = -1;
        }
        else if(rear == 0){
            rear = size-1;
        }
        else{
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(isEmpty())
            return -1;
        else
            return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(isEmpty())
            return -1;
        return arr[rear];
    }

   
};