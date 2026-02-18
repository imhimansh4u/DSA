#include <bits/stdc++.h>
using namespace std;

// Build function: builds the segment tree
void buildTree(int idx, int low, int high, int arr[], int seg[]) {
    if (low == high) {  // leaf node
        seg[idx] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    buildTree(2 * idx + 1, low, mid, arr, seg);
    buildTree(2 * idx + 2, mid + 1, high, arr, seg);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2]; // sum of left + right
}

// Query function: find sum in range [l, r]
int query(int idx, int low, int high, int l, int r, int seg[]) {
    // no overlap
    if (r < low || high < l) return 0;

    // complete overlap
    if (l <= low && high <= r) return seg[idx];

    // partial overlap
    int mid = (low + high) / 2;
    int left = query(2 * idx + 1, low, mid, l, r, seg);
    int right = query(2 * idx + 2, mid + 1, high, l, r, seg);
    return left + right;
}

// Update function: update a single element at index 'pos' to new value 'val'
void update(int idx, int low, int high, int pos, int val, int seg[]) {
    if (low == high) {  // leaf node
        seg[idx] = val;
        return;
    }

    int mid = (low + high) / 2;
    if (pos <= mid)
        update(2 * idx + 1, low, mid, pos, val, seg);
    else
        update(2 * idx + 2, mid + 1, high, pos, val, seg);

    // after update, re-calculate the current node's sum
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int seg[4 * n];  // segment tree array
    buildTree(0, 0, n - 1, arr, seg);

    cout << "\nSegment Tree built successfully!\n";

    // Example Queries
    cout << "\nEnter range (l r) to find sum: ";
    int l, r;
    cin >> l >> r;
    cout << "Sum in range [" << l << ", " << r << "] = "
         << query(0, 0, n - 1, l, r, seg) << "\n";

    // Example Update
    cout << "\nEnter index and new value to update: ";
    int pos, val;
    cin >> pos >> val;
    update(0, 0, n - 1, pos, val, seg);

    cout << "After update, sum in range [" << l << ", " << r << "] = "
         << query(0, 0, n - 1, l, r, seg) << "\n";

    return 0;
}
