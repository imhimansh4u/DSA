/* TASK-->>  You're given a string 'S' consisting of "{", "}", "(", ")", "[" and "]" .

Return true if the given string 'S' is balanced, else return false.

For example:
'S' = "{}()".

There is always an opening brace before a closing brace i.e. '{' before '}', '(' before ').
So the 'S' is Balanced.
*/
#include<iostream>
#include<stack>
using namespace std;


bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> st;
    for(int i = 0;i<s.size();i++){
        // Two conditions are possible
        //1.) if opening bracket , then -push it in stack
        char ch = s[i];
        if((ch == '(') || (ch == '[') || (ch == '{')){
            st.push(ch);
        }
        // 2.) if closing bracket , then check that at top of stack , 
        // its corresponding opening is present or not
        else{        // means closing bracket is present 
            if(!st.empty()){     // we must ensure that stack is not empty
                char top = st.top();
                if((ch == ')' && top == '(') ||  // below three lines contains all the three pairs
                (ch == '}' && top == '{') || 
                (ch == ']' && top == '[')){
                    st.pop();
                }
                else{             // it means any closing bracket is present and no matching opening is present for it.
                    return false;
                }
                
            }
            else{                 // it means stack is empty , therefore return false..
                return false;  
            }
        }
    }
    if(st.empty()){
            return true;
    }
    return false;
        
}
int main(){
    string s = "{()}";
    if(isValidParenthesis(s)){
        cout<<"The string is balanced"<<endl;
    }
    else{
        cout<<"String is unbalanced";
    }
    return 0;
}