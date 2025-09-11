#include <iostream>
using namespace std;
const int N = 1e5;
int arr[N];
int seg[4 * N];
// Build
void Build(int index, int low, int high)
{
    if (low == high)
    {
        seg[index] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    Build(2 * index + 1, low, mid);
    Build(2 * index + 2, mid + 1, high);
    seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);
}
// Query to find the maximum bwtween range ()
int query(int index, int low, int high, int l, int r)
{
    if (r < low || l > high)
        return INT_MIN;
    // complete overlap
    if (l <= low && r >= high)
    {
        return seg[index];
    }
    // Partial Overlap
    int mid = (low + high) / 2;
    int left = query(2 * index + 1, low, mid, l, r);
    int right = query(2 * index + 2, mid + 1, high, l, r);
    return max(left, right);
}
// Update index i to newVal
void update(int index, int low, int high, int i, int newVal)
{
    if (low == high)
    {
        seg[index] = newVal;
        arr[i] = newVal;
        return;
    }

    int mid = (low + high) / 2;
    if (i <= mid)
        update(2 * index + 1, low, mid, i, newVal);
    else
        update(2 * index + 2, mid + 1, high, i, newVal);

    seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);
}
int main()
{
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // build tree
    Build(0, 0, 9);
    // find max between 3 and 5
    int ans1 = query(0, 0, n - 1, 3, 5);
    cout << "The maximum between 3 and 5 is " << ans1 << endl;
    int ans2 = 0;
    ans2 = query(0, 0, n - 1, 4, 9);
    cout << ans2;
    return 0;
}