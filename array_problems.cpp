// // #include <iostream>
// // using namespace std;
// // // program to swap alternate elements in an array :: 
// // void swap_alternate(int arr[], int n)
// // {
// //     for (int i = 1; i < n; i += 2)
// //     {
// //         if (i < n)
// //         {
// //             int temp = arr[i - 1];
// //             arr[i - 1] = arr[i];
// //             arr[i] = temp;
// //         }
// //     }
// // }

// // int main()
// // {
// //     int n;
// //     cin >> n;
// //     int arr[n];
// //     // taking input of the elements ....
// //     for (int i = 0; i < n; i++)
// //     {
// //         cin >> arr[i];
// //     }
// //     swap_alternate(arr, n);
// //     for (int i = 0; i < n; i++)
// //     {
// //         cout << arr[i] << " ";
// //     }
// //     return 0;
// // }

// // program to find the uniqu element in an array :: 
// #include<iostream>
// using namespace std;
// int findUnique(int arr[], int n){
//     // int to_count = 0;
//     int count  = 0;
//     for(int i =0;i<n-1;i++){
//         for(int j=1;j<n;j++){
//             if(arr[i] == arr[j]){
//             }
//         }

//     }
// }
// int main(){
    
//     return 0;
// }

/* leetcode- problem*/
// #include<iostream>
// using namespace std;
// int findDuplicate(int arr[],int n) {
//     int ans = 0;
//     for(int i=1;i<=(n-1);i++){
//         ans ^= i;
//     }
//     for(int i=0;i<n;i++){
//         ans ^= arr[i];
//     }
//     return ans;
// }


// int main(){
//     int n = 5;
//     int arr[n]  = {1,2,3,4,3};
//     cout<<findDuplicate(arr,n);
//     return 0;
// }

// print all the elements after two arrays intersection 
#include<iostream>
using namespace std;

int main(){
    int n,m;
    n=6;
    m=4;
    int arr1[n] = {1,2,3,4,5,6};
    int arr2[m] = {2,4,6,2};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr1[i]<arr2[j])     // this is because the array is sorted ......
            break;
            if(arr1[i] == arr2[j]){
                cout<<arr1[i]<<" ";
                arr2[j] = -45;
                break; 
            }
        }
        // break;
    }
    return 0;
}