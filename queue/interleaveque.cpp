/*Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with
the second half of the queue.  

Examples:

Input :  1 2 3 4
Output : 1 3 2 4

Input : 11 12 13 14 15 16 17 18 19 20
Output : 11 16 12 17 13 18 14 19 15 20
*/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
int sizeofq(queue<int> q){
    int s = 0;
    while(!q.empty()){
        q.pop();
        s++;
    }
    return s;
}
void interleave(queue<int> &q){
    stack<int> s;
    int count = 0;
    int n = q.size();
    // push the first half of the queue into stack
    while(count!=(n/2)){
        s.push(q.front());
        q.pop();
        count++;
    }
    //enqueue the elements of stack into queue from back
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    count = 0;
    //Dequeue the first half elements of the queue and enqueue them back. 
    while(count!=(n/2)){
        q.push(q.front());
        q.pop();
        count++;
    }
    // again push the first half into stack
    count = 0;
    while(count!=(n/2)){
        s.push(q.front());
        q.pop();
        count++;
    }
    // Now perform the operation of interleave
    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> q;
    for(int i = 1;i<11;i++){
        q.push(i);
    }
    cout<<"Before interleaving"<<endl;
    print(q);
    cout<<endl;
    cout<<"after interleaving"<<endl ;
    interleave(q);
    print(q);

    return 0;
}
    