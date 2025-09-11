#include<iostream>
using namespace std;
int solve(int cnt, int k){
    if(cnt == k){
        return 1;
    }
    else{
        return 2;
    }
}

int main(){
    cout<<solve(2,5);
    return 0;
}