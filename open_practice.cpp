#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
vector<int> nextsmaller(vector<int> &arr){
    stack<int> s;
    int n = arr.size();
    vector<int> ans(n);
    s.push(-1);
    for(int i=n-1;i>=0;i--){
        int curr = arr[i];
        // if the element present at top is greater 
        while(s.top()>curr){
            s.pop();
        }
        // now top pe jo element hoga wo guarantee se chota hi hoga current element se (kyuki hm backword dirct se check krte aa rhe hai)
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
*/

// Now function to find the next greater element 
vector<int> nextgreater(vector<int> &arr){
    stack<int> s;
    s.push(-1);
    int n = arr.size();
    vector<int> ans(n);
    for(int i = n-1;i>=0;i--){
        int curr = arr[i];
        while( s.top() != -1 && s.top()<curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}


int main(){
    vector<int> v;
    v.push_back(3);
    v.push_back(7);
    v.push_back(6);
    v.push_back(8);
    v.push_back(2);
    int n = v.size();
    vector<int> ans;
    ans = nextgreater(v);
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
