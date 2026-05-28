/*                               PROBLEM STATEMENT

Given a string array nums of length n. A string is called a complete string if every prefix of this string is also present in the array nums.



Find the longest complete string in the array nums.



If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None" (without quotes).


Example 1

Input : nums = [ "n", "ni", "nin", "ninj" , "ninja" , "nil" ]

Output : ninja

Explanation :

The word "ninja" is the longest word which has all its prefixes present in the array.

Example 2

Input : nums = [ "ninja" , "night" , "nil" ]

Output : None

Explanation :

There is no string that has all its prefix present in array. So we return None.


Constraints

1 <= n <= 105
1 <= nums[i].length <= 105
1 <= sum(nums[i].length) <= 105
nums[i] consist only of lowercase English characters

*/

// Now Solution is 
// HINT ->  When uu will Construct the Trie , You will easily Understand how its soln is find 
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    class TrieNode{
        public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char ch){
            this->data = ch;
            for(int i=0;i<26;i++){
                this->children[i] = NULL;
            }
            this->isTerminal = false;
        }
    };
    void insertInTrie(TrieNode* &root,string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        TrieNode* child;
        int indx = word[0]-'a';
        if(root->children[indx] != NULL){
            child = root->children[indx];
        }else{
            child = new TrieNode(word[0]);
            root->children[indx] = child;
        }
        insertInTrie(child,word.substr(1));
    }
    void findans(TrieNode* root,string curr,string& ans){
        if(root->isTerminal == true){
            curr += root->data;
            if(curr.size()>ans.size()){
                ans = curr;
                cout<<ans<<endl;
            }
            for(int i=0;i<26;i++){
                if(root->children[i] != NULL){
                    findans(root->children[i],curr,ans);
                }
            }
        }else{
            cout<<"Entered here"<<endl;
            return;
        }
    }
    string completeString(vector<string>& nums) {
        // Initialise root for Trie
        TrieNode* root = new TrieNode('\0');
        //your code goes here
        int n = nums.size();
        // Firstly insert all the strings into nums
        for(int i=0;i<n;i++){
            insertInTrie(root,nums[i]);
        }
        string ans = "";
        string curr = "";
        for(int i=0;i<26;i++){
            if(root->children[i] != NULL){
                findans(root->children[i],curr,ans);
            }
        }
        if(ans.size() > 0){
            return ans;
        }
        return "None";
    }
};


int main(){
    // Implement Further Things Here later
    return 0;
}