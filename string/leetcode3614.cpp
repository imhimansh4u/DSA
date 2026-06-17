// 3614. Process String with Special Operations II

// You are given a string s consisting of lowercase English letters and the special characters: '*', '#', and '%'.

// You are also given an integer k.

// Build a new string result by processing s according to the following rules from left to right:

// If the letter is a lowercase English letter append it to result.
// A '*' removes the last character from result, if it exists.
// A '#' duplicates the current result and appends it to itself.
// A '%' reverses the current result.
// Return the kth character of the final string result. If k is out of the bounds of result, return '.'.

// Constraints:

// 1 <= s.length <= 105
// s consists of only lowercase English letters and special characters '*', '#', and '%'.
// 0 <= k <= 1015
// The length of result after processing s will not exceed 1015.

//NOTE-> We cannot go and Build the whole string here , Bcs it can lean to 2^(100000) which can easily Give Tle as 
// well as SLE also


// 1. Find the Final string 
// 2. reverse engineering kro , socho ki is ops ke phle wo string kaisi dikhti hogi and us string me jo k ki abhi value hai
// wo phle wale me kaisi dikhti hogi ... (THINK......)
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    char processStr(string s, long long k) {
        // firstly Find the total Length of the processed string
        long long len = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch >= 'a' && ch<='z'){
                len++;
            }else if(ch == '*'){
                len = max((long long)0,(len-1));  //Because suppose ki kisi english character ke ane se phle hi ye aagya to len-- can go to negative
            }else if(ch == '#'){
                len *= 2;
            }else{
                continue;
            }
        }
        if(k>=len) return '.';   
        // Now Process the whole String backward 
        for(int i=n-1;i>=0;i--){
            char ch = s[i];
            if(ch>='a' && ch<='z'){
                len--;
                if(len == k) return ch;  // It means this is the Requored character means the last postion in the string is kth character
            }else if(ch == '*'){
                len++;   // Because we are reversing , means is character ke phle wale state me string kaisa dikh rha hoga
            }else if(ch == '%'){
                k = (len-k-1);   //  THINK-> Because in a string, if char ch lives at i then after reversing it , its position will be len-i-1
            }else if(ch == '#'){
                len /= 2;   // because Duplication ki wjh se length bdh gyi hui rhti hai 
                if(k >= len){
                    k -= len;
                }
            }
        }
        return '.';
    }
};


int main() {
    
    return 0;
}