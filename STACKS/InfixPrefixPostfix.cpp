// Berfore we Start the -> 
/** 
Prefix Notation

In prefix notation, the operator is placed before its operands. It is also known as Polish Notation and does not require parentheses to 
determine the order of evaluation.

Example: + A B

Infix Notation

In infix notation, the operator is placed between its operands. It is the most commonly used notation in mathematics and often requires
 parentheses to specify precedence.

Example: A + B

Postfix Notation

In postfix notation, the operator is placed after its operands. It is also known as Reverse Polish Notation (RPN) and does not require
 parentheses for evaluation.

Example: A B +

***/

#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

// NOTE ----->>> 
// to_string stores the character ASCII value as a string 


// Convert Prefix representation to Infix Representation 
string PretoIn(string prefix){
    stack<string> st;
    int n = prefix.size();
    int i=n-1;
    while(i>=0){
        if(prefix[i] != '/' && prefix[i] != '*' && prefix[i] != '+' && prefix[i] != '-'){
            st.push(string(1,prefix[i]));  // converting char into string before pushing it into the stack
        }else{
            string A = st.top();
            st.pop();
            string B = st.top();
            st.pop();
            string help = "(" + A + prefix[i] + B + ")";
            st.push(help);
        }
        i--;
    }
    string ans = st.top();
    return ans;
}
//Conversion of Infix to Prefix
string IntoPre(string infix,unordered_map<char,int> &priority){
    stack<char> st;
    int n = infix.size();
    int i=n-1;
    string ans = "";
    while(i>=0){
        char ch = infix[i];
        if(ch != '+' && ch != '-' && ch!='*' && ch != '/' && ch != '(' && ch != ')'){
            ans += ch;
        }else if(ch == ')'){
            st.push(ch);
        }else if(ch == '('){
            while(!st.empty() && st.top() != ')'){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && priority[ch] < priority[st.top()]){
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
        i--;
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


// Covert PostToIn (PostFix Representation into Infix)
string PosttoIn(string postfix){
    int i=0;
    int n = postfix.size();
    stack<string> st;
    while(i<n){
        if(postfix[i] != '/' && postfix[i] != '*' && postfix[i] != '+' && postfix[i] != '-'){
            st.push(string(1,postfix[i]));  // converting char into string before pushing it into the stack
        }else{
            string A = st.top();
            st.pop();
            string B = st.top();
            st.pop();
            string help = "(" + B + postfix[i] + A + ")";
            st.push(help);
        }
        i++;
    }
    return st.top();
}

// INFIX TO POSTFIX
/*
Ah, Infix to Postfix! That makes total sense. This is actually the most famous and foundational expression conversion algorithm in computer
 science. It is called the Shunting-Yard Algorithm, invented by Edsger Dijkstra.

To understand it deeply, we have to look at the problem from the computer's perspective. When a computer reads an infix expression like
 A + B * C, it reads from left to right.

When it sees +, it can't execute it yet because it doesn't know if a higher-priority operator (like *) is coming next.

Therefore, the computer needs a "waiting room" to hold onto operators until it's their turn to be executed. That waiting room is our Stack.
*/

// ALGORITHM
/*
:

🧭 Infix to Postfix Algorithm Checklist
1.Scan the Infix string from left to right, character by character.

2.If the character is an Operand, append it directly to the output string (ans).

3.If the character is an Opening Bracket (, push it immediately onto the stack.

4.If the character is a Closing Bracket ), pop operators from the stack to the output string until an opening bracket ( is encountered at the top, then pop and discard the (.

5.If the character is an Operator, continuously pop from the stack to the output string while the stack is not empty and the precedence of the operator at st.top() is greater than or equal to the current operator's precedence; then push the current operator onto the stack.

6.After scanning the entire string, pop all remaining operators left in the stack one by one and append them to the output string.
*/
// + and - both have same precedance in programming and any Normal thing also , also * and / have same Priority 
string IntoPost(string infix,unordered_map<char,int>& priority){
    stack<char> st;
    string ans = "";
    int n = infix.size();
    for(int i=0;i<n;i++){
        if(infix[i] != '/' && infix[i] != '*' &&  infix[i] != '+' &&  infix[i] != '-' &&  infix[i] != '(' && infix[i] != ')'){
            ans += infix[i];
        }else if(infix[i] == '('){
            st.push('(');
        }else if(infix[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && priority[infix[i]] <= priority[st.top()]){
                ans += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

// Now Converting PreFix to Postfix
string PretoPost(string prefix){
    stack<string> st;
    int n = prefix.size();
    int i = n-1;
    while(i>=0){
        char ch = prefix[i];
        if(ch != '+' && ch != '-' && ch != '*' && ch != '/'){
            st.push(string(1,ch));
        }else{
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            string news = a+b+string(1,ch);
            st.push(news);
        }
        i--;
    }
    return st.top();
}

string PosttoPre(string prefix){
    stack<string> st;
    int n = prefix.size();
    int i = 0;
    while(i<n){
        char ch = prefix[i];
        if(ch != '+' && ch != '-' && ch != '*' && ch != '/'){
            st.push(string(1,ch));
        }else{
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            string news = string(1,ch)+b+a;
            st.push(news);
        }
        i++;
    }
    return st.top();
}



int main(){
    unordered_map<char,int> priority;
    priority['/'] = 2;
    priority['*'] = 2;
    priority['+'] = 1;
    priority['-'] = 1;
    cout<<PretoIn("+A*BD")<<endl;
    cout<<PosttoIn("ABC*+DEF/-*")<<endl;
    cout<<IntoPost("a+b-c*d+(e+f*j)",priority)<<endl;
    cout<<IntoPre("(A+(B*D))",priority)<<endl;
    cout<<PretoPost("+A*BD")<<endl;
    cout<<PosttoPre("ABD*+")<<endl;
    return 0;

}