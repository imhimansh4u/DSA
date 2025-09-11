#include<iostream>
#include<queue>
using namespace std;

// using stl queue..

/*
class queuee{
    queue<int> q;
    public:
    void push(int data){
        q.push(data);
    }
    void pop(){
        q.pop();
    }
    int size(){
        return q.size();
    }
    bool isempty(){
        return q.empty();
    }
    int front(){
        return q.front();
    }
};


int main(){
    queuee a;
    a.push(3);
    a.push(5);
    cout<<a.front()<<endl;
    a.push(56);
    a.pop();
    cout<<a.front()<<endl;
    cout<<a.isempty();
    return 0;
}

*/

// Now implementation of queue using array

class Queue {
    int frontt;
    int *arr;
    int rear;
    int size;
    public:
    Queue() {
        // Implement the Constructor
        size = 10000000;
        arr = new int[size];     // size of the array is given random , just for understanding purpose..
        frontt = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(frontt  == rear){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear == size){
            cout<<"stack is full";
        }
        else{
            arr[rear] = data;   
            rear ++;         // rear will point to the next memory block after the block wheere last data is inserted..
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()){
            return -1;
        }
        else{
            int ans  = arr[frontt];
            arr[frontt] = -1;
            frontt++;
            if(frontt == rear){
                frontt = -1;
                rear = -1;
            }
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[frontt];
        }
    }
};