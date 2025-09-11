
// #include<iostream>
// using namespace std;
// int count_bit(int n){
//     int count =0;
//     while(n!=0){
//         if(n^1){
//             count++;
//         }
//         n = n>>1;
//     }
//     return count;
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<count_bit(n);
//     return 0;
// }

// // H.W que --(2) print the nth fibonacci series term..
// #include<iostream>
// using namespace std;
// int fib_series(int n){
//     int a= 0;
//     int b = 1;
//     int fib_term = 0;
//     for(int i=1;i<=n-2;i++){
//         // int temp = b;
//         fib_term = a+b;
//         a = b;
//         b = fib_term;
//     }
//     return fib_term;
// }

// int main(){
//     cout<<fib_series(5);
//     return 0;
// // }
// #include<iostream>
// using namespace std;

// int main(){
//     int n = 5;
//     int arr[5] = {};
//     for(int i = 0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }
// #include<iostream>
// using namespace std;
// void reverse_array(int arr[],int n){
//     for(int i =0;i<n/2;i++){
//         int temp = arr[i];
//         arr[i] = arr[n-1-i];
//         arr[n-1-i] = temp;
//     }
// }

// int main(){
//     int arr[5] = {1,2,3,4,5};
//     reverse_array(arr,5);
//     for(int i=0;i<5;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }
// #include<iostream>
// using namespace std;

// int main(){
//     int n = 10;
//     int arr[n] = {1,2,3,4,1,4,5,5,7,8};
//     int count = 0;
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i] == arr[j])
//             count++;
//         }
//     }
//     cout<<count;
//     return 0;
// }
// important code to find the first and last occurance of any element in an array ::
// pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k) {
//   // Write your code here
//   int i = 0;
//   int j = n-1;
//   int first = -1;
//   int last = -1;
//   while (i <= j) {
//     int mid = i + (j - i) / 2;
//     if (arr[mid] == k) {
//       int copy_mid = mid;
//       while (arr[mid - 1] == k) {
//         mid--;                                           // ye pura code shi hai pr tle maar jaega............
//       }
//       first = mid;
//       while (arr[copy_mid + 1] == k) {
//         copy_mid++;
//       }
//       last = copy_mid;
//     } else if (arr[mid] < k) {
//       i = mid + 1;
//     } else {
//       j = mid - 1;
//     }
//   }
//   pair<int,int> p;
//   if(first == -1){
//       p.first = -1;
//       p.second = -1;
//   }
//   else{
//       p.first = first;
//       p.second = last;
//   }
//   return p;
// }
// #include <iostream>
// #include <cmath>
// #include <math.h>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     int i = sqrt(n);
//     cout << i;
//     return 0;
// }
// #include <bits/stdc++.h> 
// using namespace std;
// vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
// 	// Write your code here.
// 	int firstnum;
// 	int secnum;
// 	int i = 0;
// 	while(i<n){
// 		firstnum = a[i]*pow(10,n-i-1);
// 		i++;
// 	}
// 	int j = 0;
// 	while(j<m){
// 		secnum = a[j]*pow(10,m-j-1);
// 		j++;
// 	}
// 	int finalnum = firstnum + secnum;
// 	vector<int> final_arr;
// 	while(finalnum != 0){
// 		int dig = finalnum%10;
// 		final_arr.push_back(dig);
// 		finalnum /= 10;
// 	}
// 	int final_size = final_arr.size();
// 	vector<int> temp(final_size);
// 	for(int i =0;i<final_size;i++){
// 		temp[i] = final_arr[final_size-1-i];
// 	}
// 	return temp;
// }
// int main(){
//     vector<int> a(3);
//     a.push_back(3);
//     a.push_back(9);
//     a.push_back(1);
//     vector<int> b(4);
//     b.push_back(3);
//     b.push_back(1);
//     b.push_back(8);
//     b.push_back(9);
//     findArraySum(a,3,b,4);

//     return 0;
// }
// #include<iostream>
// using namespace std;

// int main(){
// 	int arr[5] = {1,2,3,4,5};
// 	for(int i = 0;i<5;i++){
// 		cout<<i[arr]<<" ";
// 	}
// 	return 0;
// #include<iostream>
// #include<string>
// using namespace std;

// int main(){
// 	string ans = "";
// 	ans.append("d");
// 	cout<<ans;
// 	return 0;
// }
// #include<iostream>
// using namespace std;
// int fib(int n){
// 	if(n==1 || n ==2){
// 		return 1;
// 	}
// 	return fib(n-1)+fib(n-2);
// }

// int main(){
// 	int n = 8;
// 	cout<<fib(n);
// 	return 0;
// }
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<vector<int>> v = {{1,2},{7,9},{5,3}};
	sort(v.begin(),v.end());
	for(auto i : v){
		for(auto j : i){
			cout<<j<<" ";
		}
	}
	return 0;
}