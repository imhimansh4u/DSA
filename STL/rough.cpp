#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<string> arr = {"act", "god", "cat", "dog", "ta"};
    for(int i =0 ;i<arr.size();i++){
        sort(arr[i].begin(),arr[i].end());
    }
    return 0;
}