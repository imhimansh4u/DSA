// The Task here is to find the length and then the actual longest Common Substring
// ............. substring -> contiguous and in order 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Finds the length first using a 2D table, then reconstructs the actual string
string findLCSWith2DTable(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();

    if (m == 0 || n == 0) return "";

    // Step 1: Create and initialize the 2D DP table with 0s
    // dp[i][j] stores the length of the longest common suffix of s1[0..i-1] and s2[0..j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    int maxLength = 0;
    int maxI = 0; // Row index where the maximum length occurs
    int maxJ = 0; // Column index where the maximum length occurs

    // Step 2: Forward Phase - Populate the DP table to find the maximum length
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                
                // Track the maximum value and its coordinates in the matrix
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    maxI = i;
                    maxJ = j;
                }
            } else {
                dp[i][j] = 0; // Substrings must be continuous; reset on mismatch
            }
        }
    }

    // If no common characters were found at all
    if (maxLength == 0) return "";

    // Step 3: Backward Phase - Reconstruct the substring using the DP table
    string result = "";
    int i = maxI;
    int j = maxJ;

    // Backtrack diagonally up and left as long as the cell values match our chain
    while (maxLength > 0 && i > 0 && j > 0 && dp[i][j] > 0){
        result += s1[i - 1]; // Append the matching character
        i--;
        j--;
        maxLength--; // Move to the previous element in the match chain
    }
    
    // Since we collected characters backward from the end, reverse the string to get the correct order
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string s1 = "OldSiteNewSite";
    string s2 = "NewSiteOldSite";

    string lcs = findLCSWith2DTable(s1, s2);

    cout << "Longest Common Substring: \"" << lcs << "\"" << endl;
    cout << "Length of Substring: " << lcs.length() << endl;

    return 0;
}