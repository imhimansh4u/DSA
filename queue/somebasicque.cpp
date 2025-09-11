// Que. 1)) Reverse a Queue 
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
// APPROACH 1-->> with the help of property of stack ..  T.C.-> O(n) AND S.C. -> O(n)....
// NOte --> stack ki property hoti hai usme elements ko daal ke waps nikaloge to wo reverse order me ayenge ..
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int> s;
        // add code here.
        while(!q.empty()){
            s.push(q.front());   // phle stack me sare elements ko dalo
            q.pop();
        }
        while(!s.empty()){
            q.push(s.top());   // fir sare ko nikal ke queue me append kr do 
            s.pop(); 
        }
        return q;
    }
};


//APPRAOCH 2--))  T.C.-> O(N) AND S.C. -> O(1)  
class Solution
{
    public:
    void reverse(queue<int> &q){
        // base case
        if(q.empty()){
            return;
        }                // understand it by your own..
        int val  = q.front();
        q.pop();
        reverse(q);
        q.push(val);
    }
    queue<int> rev(queue<int> q)
    {
        // add code here.
        reverse(q);
        return q;
    }
};

int main(){
    return 0;
}