#include<iostream>
#include<vector>
using namespace std;

int FindGParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = FindGParent(parent, parent[node]);
}
void DSU(vector<int> &parent, vector<int> &rank, int u, int v)
{
    if (u == v)
    {
        return;
    }
    int up = parent[u];
    int vp = parent[v];
    if (rank[up] < rank[vp])
    {
        parent[up] = vp;
    }
    else if (rank[vp] < rank[up])
    {
        parent[vp] = up;
    }
    else
    {
        parent[up] = vp;
        rank[vp]++;
    }
}
int main(){

    return 0;
}