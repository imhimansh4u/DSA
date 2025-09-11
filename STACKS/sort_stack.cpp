// TASK-->> sort a stack in descending order (top pe sbse bda element)....
#include<iostream>
#include<stack>
using namespace std;
// very mast method for ((sorted inserting )) 
void sortedinsert(stack<int> &s,int x){
	// 1st base case
	if(s.empty()){
		s.push(x);
		return;
	}
	// 2nd base case
	if(s.top()<x){          // jo bhi top element mile joki x se cchota hai iska mtlb uske niche wala part sorted hai whi insert kr do....
		s.push(x);
		return;
	}
	int ele = s.top();
	// pop it
	s.pop();
	// recursive call
	sortedinsert(s,x);
	// waps se wo element daal do
	s.push(ele);
}
void sortStack(stack<int> &stack)
{
    // phle pura stack khali kro
	if(stack.empty()){
		return;
	} 
	int el = stack.top();
	stack.pop();
	sortStack(stack);
    // waps jate time el ko sorted insert kr do....
	sortedinsert(stack, el);
}
// baki kr lena khud se .. upr ka code complete and shi hai ekdm.
int main(){

    return 0;
}
