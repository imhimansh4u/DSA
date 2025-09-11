 /*Inversion Count for an array indicates that how far (or close) the array is from being sorted.
  If the array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order, 
  the inversion count is the maximum. */

//    M1-- brute force technique( T.c. = O(n*n))
// #include <iostream>
// #include <vector>
// using namespace std;
// int inversion_count(int arr[], int n)
// {
//     int count = 0;
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[i])
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// int main()
// {
//     int arr[4] = {7,2,6,3};
//     cout<<inversion_count(arr,4);
//     return 0;
// }


// m2 -- by using the concept of merge sort ..

#include <bits/stdc++.h>
using namespace std;

// This function merges two sorted subarrays
// arr[l...m] and arr[m+1 .. r] and also counts
// inversions in the whole subarray arr[l..r]
long long countAndMerge(vector<long long>& arr, int l, int m, int r){
    // Counts in two subarrays
    int n1 = m - l + 1, n2 = r - m;

    // Set up two vectors for left and right halves
    vector<long long> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    // Initialize inversion count (or result)
    // and merge two halves
    long long res = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {

        // No increment in inversion count
        // if left[] has a smaller or equal element
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        }
        // If right is smaller, then it
        // is smaller than n1-i elements
        // because left[] is sorted
        else {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }

    // Merge remaining elements
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return res;
}

// Function to count inversions in the array
long long countInv(vector<long long>& arr, int l, int r){
    long long res = 0;
    if (l < r) {
        int m = (r + l) / 2;

        // Recursively count inversions
        // in the left and right halves
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);

        // Count inversions such that greater
        // element is in the left half and
        // smaller in the right half
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

int main(){
    vector<long long> arr = { 4, 3, 2, 1 };
    int n = arr.size();
    cout << countInv(arr, 0, n - 1)<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


