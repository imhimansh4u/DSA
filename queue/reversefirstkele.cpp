/*Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, 
leaving the other elements in the same relative order.
*/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Solution
{
    public:
    // function to find the size of queue..
    int sizeofqueue(queue<int> q){
        int size = 0;
        while(!q.empty()){
            q.pop();
            size++;
        }
        return size;
    }
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        int size = sizeofqueue(q);
        stack<int> s;        // helping thing
        // add code here.
        int count = 0;
        while(count != k){      // push first (k) elements into stack
            s.push(q.front());
            q.pop();
            count++;
        }
        while(!s.empty()){  // again push them in the stack , but this time in reversed order
            q.push(s.top());
            s.pop();
        }
        count = 0;
        while(count != (size-k)){  // put the remaining elements on their correct position
            int el = q.front();
            q.pop();
            q.push(el);
            count++;
        }
        return q;
    }
};

int main(){
    
    return 0;
}