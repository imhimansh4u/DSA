#include<iostream>
#include<algorithm>
using namespace std;
 // only possible for square matris (where rows = col) .here (m = n)..
int main(){
    int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}} ;
    int arr2[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}} ;
    int m= 4;
    int n = 4;
    cout<<"The original array is:: "<<endl;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //flipping across main dioganal
    for(int i = 0;i<n;i++ ){
        for(int j = i+1;j<m;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    //flipping across anti-dioganal
    for(int i =0;i<n;i++){
        for(int j = 0;j<(n-i-1);j++){
            swap(arr2[i][j],arr2[n-1-j][n-i-1]);
        }
    }
    cout<<"after flipping across the main dioganal :: "<<endl;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"after flipping across the anti dioganal :: "<<endl;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}