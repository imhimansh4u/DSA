// problem statement -->> given a string .. return its all possible subsequences

#include <bits/stdc++.h>
using namespace std;
void solve(string str,vector<string> &ans,string subs,int index){
	// base case
	if(index>=str.size()){
		ans.push_back(subs);
		return;
	}
	if(index == 0){
		//include karo
		subs.push_back(str[index]);
		solve(str,ans,subs,index+1);
	}
	else{
		//exclude karo
		solve(str,ans,subs,index+1);
		//include karo
		subs.push_back(str[index]);
		solve(str,ans,subs,index+1);
	}
} 
vector<string> subsequences(string str){
	vector<string> ans;       // for the main answer
	string subs ;             // for the strings inside the main answer
	int index = 0;
	solve(str,ans,subs,index);
	return ans;
}
int main(){
	string str = "Himanshu";
	vector<string> ans;
	ans = subsequences(str);
	for(int i=0;i<ans.size()-1;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
