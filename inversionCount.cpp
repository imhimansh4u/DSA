// The task here is to find INversion count (How far or close a array is to sorted array) 
// OR find the pair (i,j) in which i<j and arr[i]>arr[j]
// for e.g. in [3, 1, 2, 5, 4] here pairs are --> (3,1),(3,2),(5,4)  --->>> TOTAL of 3 therfore its answer is 3

#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int>& arr, int l, int mid, int r) {

    vector<int> temp;

    int i = l;
    int j = mid + 1;

    long long cnt = 0;

    while(i <= mid && j <= r) {

        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            // arr[i] > arr[j]
            // so all elements from i...mid are also > arr[j]
            cnt += (mid - i + 1);

            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= r) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int k = l; k <= r; k++) {
        arr[k] = temp[k - l];
    }

    return cnt;
}


long long mergeSort(vector<int>& arr, int l, int r) {

    if(l >= r)
        return 0;

    int mid = l + (r - l) / 2;

    long long cnt = 0;

    cnt += mergeSort(arr, l, mid);
    cnt += mergeSort(arr, mid + 1, r);

    cnt += merge(arr, l, mid, r);

    return cnt;
}


int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << mergeSort(arr, 0, n - 1);

    return 0;
}