#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
void combination(string digits,vector<string>& ans,string output,int i){
        // mapping for numbers
        string mapp[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(i>=digits.length()){
            ans.push_back(output);
            return;
        }
        int num = digits[i] - '0';   // extracting the number
        int j = 0;
        while(j<mapp[num].length()){
            output.push_back(mapp[num][j]);
            combination(digits,ans,output,i+1);
            output.pop_back();    // This holds a little concept of backtracking .....(always Draw recursive tree to understand it better)
            j++;
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0){
            return ans;
        }
        string output = "";
        int i = 0;
        combination(digits,ans,output,i);
        return ans;
    }
};
int main(){
    string digits;
    cout<<"Enter the numbers from dial pad (2 to 9) to see the combinations  :: ";
    cin>>digits;
    Solution s1;
    vector<string> ans =  s1.letterCombinations(digits);
    for(int i = 0 ;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}