#include<iostream>
using namespace std;
// function to find the length of the string......
int getlength(char name[]){
    int count = 0;
    int i = 0;
    while(name[i] != '\0'){
        count++;
        i++;
    }
    return count;
}
//function to reverse the string 
void reversestring(char name[],int n){
    int s = 0;
    int e = n-1;
    while(s<=e){
        char temp = name[s];
        name[s] = name[e];
        name[e] = temp;
        s++;
        e--;
    }
}



int main(){
    char name[9] = {'a','b','c'};
    int n = getlength(name);
    reversestring(name,n);
    cout<<name;

    return 0;
}