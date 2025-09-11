#include <bits/stdc++.h> 
using namespace std;
class CircularQueue{
    int *arr;
    int size;
    int front;
    int rear;    //in this rear will point to the memory block of the last inserted element..
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if((front == 0 && rear == size-1) || (rear == (front-1))){
            return false;
        }
        else if(front == -1){
            front++;
            rear++;
            arr[front] = value;
            return true;
        }
        else if(rear == (size-1) && front != 0){   // this is the main condition of circular queue that if empty space is left at starting then we
                                                    //   can again insert elements there by pointint tthe rear pointer there 
            rear = 0;
            arr[rear] = value;
            return true;
        }
        else{
            rear++;
            arr[rear] = value;
            return true;;
        }
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        int ans = arr[front];
        if(front ==  -1){
            return -1;
        }
        else if(front == rear){    // it means single element is present       
            front = rear = -1;
            return ans;
        }
        else if(front == size-1){   // it means front is the last element in the queue , then point it back to the starting
            front = 0;
            return ans;
        }
        else{
            front++;
            return ans;
        }
    }
};