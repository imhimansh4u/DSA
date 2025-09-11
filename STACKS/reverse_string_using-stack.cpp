#include<iostream>
#include<stack>

using namespace std;

void reverse_string(string &s , stack<char> st){
    int n = s.size();
    for(int i = 0;i<n;i++){
        st.push(s[i]);
    }
    // now reversing the string
    for(int i =0;i<n;i++){
        s[i] =  st.top();
        st.pop();
    }
}

int main(){
    string s = "deepu";
    stack<char> st;
    reverse_string(s,st);
    // to print the stack
    for(int i = 0;i<s.size();i++){
        cout<<s[i]<<" ";
    }
    return 0;
}