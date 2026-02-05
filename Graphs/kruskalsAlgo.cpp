// Helps TO find MST

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void makeSet(vector<int> &parent, vector<int> &rank, int n) // For the initialisation of parent array and rank of each node
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findGparent(vector<int> &parent, int node) // Helps to detect that if any cycle is present or not
{
    if (parent[node] == node)
    {
        return;
    }
    return parent[node] = findGparent(parent, parent[node]);
}

void unionSet(vector<int> &parent, vector<int> &rank, int u, int v)
{
    int uParent = parent[u];
    int vParent = parent[v];

    if (rank[uParent] < rank[vParent])
    {
        parent[uParent] = vParent;
    }
    else if (rank[vParent] < rank[uParent])
    {
        parent[vParent] = uParent;
    }
    else
    {
        parent[vParent] = uParent;
        rank[uParent]++;
    }
}
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

// In this function , we have to return the total path cost of minimum spanning tree (MST)
int minMST(vector<vector<int>> &edges, int n)
{ // n is the no. of nodes (0 to (n-1))
    vector<int> parent;
    vector<int> rank;
    makeSet(parent, rank, n); // To initialize parent and rank
    // sort the edges based on the weights
    sort(edges.begin(), edges.end(), cmp);
    int ans = 0;

    for (auto ele : edges)
    {
        int u = ele[0];
        int v = ele[1];
        int w = ele[2];

        if (findGparent(parent, u) != findGparent(parent, v))
        {
            ans += w;
            unionSet(parent, rank, u, v);
        }
    }
    return ans;
}

int main()
{

    return 0;
}