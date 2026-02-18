#include <iostream>
#include <vector>

using namespace std;

/* 1.-> For range Updates in [l,r] range with update each value with addition of val
    2.-> lazy is the array which holds the lazy Propagation value
    3.-> indx is the index inside the segement Tree
    4.-> low and high are the range of original array
    5.-> seg is the segment Tree
*/
void rangeUpdate(int indx, int low, int high, int l, int r, int val, vector<int> &lazy, vector<int> &seg)
{
    // Firstly check that if any laazy update value is pending or not
    if (lazy[indx] != 0)
    {
        seg[indx] += (high - low + 1) * lazy[indx];
        if (low != high)
        { // it means no leaf index , then pass the lazy value to the left and right child also
            lazy[2 * indx + 1] = lazy[indx];
            lazy[2 * indx + 2] = lazy[indx];
        }
        lazy[indx] = 0; // in last lazy value at that perticular index is 0
    }
    // Now check for Out of Bound condition
    if (r < low || l > high || low > high)
    {
        return;
    }
    // Now check that if [low,high] completely lies inside the range [l,r]
    if (low >= l && high <= r)
    {
        // then update its value
        seg[indx] += (high - low + 1) * val;
        // Now update the lazy value of left and right child if exists
        if (low != high)
        {
            lazy[2 * indx + 1] = val;
            lazy[2 * indx + 2] = val;
        }
    }
    // if partially lies , Then go in left and right side
    int mid = (high - low) >> 1; //  finds out n/2
    rangeUpdate(2 * indx + 1, low, mid, l, r, val, lazy, seg);
    rangeUpdate(2 * indx + 2, mid + 1, high, l, r, val, lazy, seg);

    // In last Update the Final value during backtracking
    seg[indx] = seg[2 * indx + 1] + seg[2 * indx + 2];
    return;
}

// Now Function for range sum value
int rangeSum(int indx, int low, int high, int l, int r, int val, vector<int> &lazy, vector<int> &seg)
{
    // check if lazy value is remaining for this index or not
    if (lazy[indx] != 0)
    {
        seg[indx] += (high - low + 1) * lazy[indx];
        if (low != high)
        { // it means no leaf index , then pass the lazy value to the left and right child also
            lazy[2 * indx + 1] = lazy[indx];
            lazy[2 * indx + 2] = lazy[indx];
        }
        lazy[indx] = 0; // in last lazy value at that perticular index is 0
    }
    // Now check for Out of Bound condition
    if (r < low || l > high || low > high)
    {
        return;
    }
    if (low >= l && high <= r)
    {
        return seg[indx];
    }
    int mid = (high - low) >> 1;
    return rangeSum(2 * indx + 1, low, mid, l, r, val, lazy, seg) + rangeSum(2 * indx + 2, mid + 1, high, l, r, val, lazy, seg);
}

int main()
{
    return 0;
}