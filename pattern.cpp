#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n :: "<<endl;
    cin>>n;
    /*
            NOTE -- mst pattern question (to revise you about simple pattern techniques....)
    int row= 1;
    while(row<=n){
        int count  = 1;
        int col = 1;
        while (col<n-row+1)
        {
            cout<<"  ";
            col++;
        }
        col = n-row+1;
        while(col<=n){
            cout<<count<<" ";
            col++;
            count ++;
        }
        col = row-1;
        count = row-1;
        while(col>0){
            cout<<count<<" ";
            col--;
            count--;
        }
        col = row;
        while(col<n){
            cout<<"  ";
            col++;
        }
        cout<<endl;
        row++;
    }
    */
    //   NOTE -- another mst pattern que.............
    int row = 1;
    while(row<=n){
        int col = 1;
        int count = 1;
        while(col<=n-row+1){
            cout<<count;
            col++;
            count++;
        }
        col = 1;
        count  = row-1;
        while(col<=(2*count)){
        cout<<"*";
        col++;
        }
        col = 1;
        count = n-row+1;
        while(col<=(n-row+1)){
            cout<<count;
            col++;
            count--;
        }
        cout<<endl;
        row++;
    }
    return 0;
}
