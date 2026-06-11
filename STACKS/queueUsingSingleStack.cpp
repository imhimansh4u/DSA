// NOTE ->  Implementing queue using two stacks is more efficient , but lets try it with one stack + Recursion
#include <iostream>
#include <vector>
#include<stack>
using namespace std;

class QueueUsingStack{
    public:
    stack<int> st;
    QueueUsingStack(){}
    void add(int x){
        st.push(x);
        return;
    }
    int popfrontUtil(int i,int n,stack<int> st){
        if(st.empty()) return -1;
        int ele = st.top();
        st.pop();
        if(i == n){
            return ele;
        }
        return popfrontUtil(i+1,n,st);
        st.push(ele);
    }
    int popfront(){
        return popfrontUtil(1,st.size(),st);
    }
};

int main() {
    QueueUsingStack eg1;
    eg1.add(3);
    eg1.add(4);
    eg1.add(5);
    cout<<eg1.popfront();
    return 0;
}