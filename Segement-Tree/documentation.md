# 📘 Segment Tree – Complete Documentation

---

## 🔹 1. Introduction

A **Segment Tree** is a binary tree data structure used for **efficient range queries and range updates** on an array.

Typical problems solved using Segment Trees:

* Find **sum**, **minimum**, or **maximum** in a given range.
* Update an element or a range of elements quickly.

It provides:

* **Range Query:** O(log n)
* **Range Update (without lazy):** O(log n)
* **Range Update (with lazy):** O(log n)

Segment Trees are widely used in competitive programming and real-time systems like database query engines or games.

---

## 🔹 2. Structure of a Segment Tree

For an array `arr` of size `n`, a Segment Tree is represented as an array `seg` of size around `4 * n`.

Each node represents information about a **range** `[l, r]` of the original array.

* The **root node (index 0)** → represents the entire range `[0, n-1]`.
* The **left child (2*i + 1)** → represents range `[l, mid]`.
* The **right child (2*i + 2)** → represents range `[mid + 1, r]`.

### 🧩 Example

```
Array: [1, 3, 5, 7, 9, 11]

Segment Tree Representation (for sum):

                       [0,5]=36
                     /           \
             [0,2]=9             [3,5]=27
             /    \               /    \
         [0,1]=4 [2,2]=5   [3,4]=16  [5,5]=11
         /   \               /   \
     [0,0]=1 [1,1]=3   [3,3]=7 [4,4]=9
```

Each node stores the **sum of its range**.

---

## 🔹 3. Building the Segment Tree

The tree is built recursively:

1. If `low == high`, it is a leaf node → store `arr[low]`.
2. Otherwise:

   * Build left and right children.
   * Store `seg[idx] = seg[left] + seg[right]`.

Time Complexity: **O(n)**

---

## 🔹 4. Range Sum Query

To find the **sum of a given range [L, R]**:

1. **No Overlap:** If the current segment is completely outside [L, R] → return 0.
2. **Complete Overlap:** If the segment is completely inside [L, R] → return its value.
3. **Partial Overlap:** Recurse into both left and right children.

Time Complexity: **O(log n)**

---

## 🔹 5. Point Update

If one element changes, update the relevant leaf and recompute all its ancestors.

Time Complexity: **O(log n)**

---

## 🔹 6. Problem with Normal Segment Tree – Range Updates

Suppose you want to **add 3 to every element in the range [2, 5]**.

If we use the normal approach, we must update all elements → **O(n)** time.

But Segment Trees can be optimized using **Lazy Propagation**.

---

## 🔹 7. Lazy Propagation Concept

**Idea:**
We "delay" updates to child nodes until they are needed. Instead of immediately updating all affected nodes, we mark them as **lazy**.

### 🧠 How It Works

* Maintain an additional array `lazy[]`.
* `lazy[idx]` stores the value that needs to be added to node `idx` later.
* When visiting a node, apply the lazy value (if any) and propagate it to children.

This avoids unnecessary traversal and keeps updates efficient.

---

## 🔹 8. Lazy Propagation Update

### Steps to Update Range [l, r] by val:

1. If a node has a pending lazy value, apply it first.
2. If no overlap → return.
3. If complete overlap → update node and mark children lazy.
4. If partial overlap → recursively update children and recompute.

Time Complexity: **O(log n)**

---

## 🔹 9. Lazy Propagation Query

### Steps to Query Range [l, r]:

1. If the node has pending updates → apply them first.
2. If no overlap → return 0.
3. If complete overlap → return node value.
4. If partial overlap → query both children and sum.

Time Complexity: **O(log n)**

---

## 🔹 10. Example Diagram (Range Update)

Example: Add 10 to range [1, 3]

```
Before:
         [0,5]=36
        /         \
    [0,2]=9     [3,5]=27

After lazy update:

Lazy array marks pending updates:
    lazy[0]=0
    lazy[1]=10  (affects [1,3])

We only apply the updates when we visit [1,3] again during query.
```

---

## 🔹 11. C++ Implementation (Complete)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int seg[4*N], lazy[4*N];

void build(int idx, int low, int high, int arr[]) {
    if (low == high) {
        seg[idx] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2*idx+1, low, mid, arr);
    build(2*idx+2, mid+1, high, arr);
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

void updateRange(int idx, int low, int high, int l, int r, int val) {
    if (lazy[idx] != 0) {
        seg[idx] += (high - low + 1) * lazy[idx];
        if (low != high) {
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if (r < low || high < l) return;

    if (low >= l && high <= r) {
        seg[idx] += (high - low + 1) * val;
        if (low != high) {
            lazy[2*idx+1] += val;
            lazy[2*idx+2] += val;
        }
        return;
    }

    int mid = (low + high) / 2;
    updateRange(2*idx+1, low, mid, l, r, val);
    updateRange(2*idx+2, mid+1, high, l, r, val);
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

int queryRange(int idx, int low, int high, int l, int r) {
    if (lazy[idx] != 0) {
        seg[idx] += (high - low + 1) * lazy[idx];
        if (low != high) {
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if (r < low || high < l) return 0;

    if (low >= l && high <= r) return seg[idx];

    int mid = (low + high) / 2;
    return queryRange(2*idx+1, low, mid, l, r) + queryRange(2*idx+2, mid+1, high, l, r);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    build(0, 0, n-1, arr);

    cout << "\nInitial sum of range [1,4]: " << queryRange(0, 0, n-1, 1, 4);

    updateRange(0, 0, n-1, 1, 4, 3);

    cout << "\nAfter adding 3 in range [1,4]: " << queryRange(0, 0, n-1, 1, 4) << endl;
}
```

---

## 🔹 12. Why We Use Lazy Propagation

| Scenario      | Normal Segment Tree | Lazy Segment Tree  |
| ------------- | ------------------- | ------------------ |
| Single Update | O(log n)            | O(log n)           |
| Range Update  | O(n)                | ✅ O(log n)         |
| Range Query   | O(log n)            | ✅ O(log n)         |
| Memory        | O(4n)               | O(4n) + O(4n lazy) |

Lazy propagation avoids redundant updates, making the segment tree efficient for problems involving **many range updates**.

---

## 🔹 13. Real-Life Analogy

Imagine you have to give every student in a class +5 marks:

* Without lazy propagation → you go to each student and add 5.
* With lazy propagation → you mark the class as "+5 pending" and only calculate when needed.

---

## 🔹 14. Applications

* Range Sum Queries (Addition)
* Range Minimum/Maximum Queries
* Range Increment/Decrement
* 2D Range Queries (e.g., images or grids)
* Real-time simulations, finance, and analytics

---

## 🔹 15. Summary Table

| Operation    | Without Lazy | With Lazy  |
| ------------ | ------------ | ---------- |
| Build        | O(n)         | O(n)       |
| Point Update | O(log n)     | O(log n)   |
| Range Update | ❌ O(n)       | ✅ O(log n) |
| Range Query  | O(log n)     | O(log n)   |

---

## 🧾 Final Notes

* Segment Trees are **powerful for range operations**.
* Lazy Propagation makes them **efficient for bulk updates**.
* Implementation requires careful management of **indices and lazy values**.

---

**End of Document**
