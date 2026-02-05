#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // To find the Parent
    int findParent(vector<int> &parent, int &node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent, parent[node]); // Path compression
    }

    // To set the initial nodes and components
    void makeSet(vector<int> &parent, vector<int> &rank, int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;   // Initially we make parent of node to be itslef
            rank[i] = 0;     // and rank of all the nodes to be 0
        }
    }

    // To find Union by Rank
    void findUnionByRank(int &u, int &v, vector<int> &parent, vector<int> &rank)
    {
        int parent_u = findParent(parent, u);
        int parent_v = findParent(parent, v);

        if (parent_u == parent_v)
            return; // Already in same set

        if (rank[parent_u] > rank[parent_v])
        {
            parent[parent_v] = parent_u;  // Merege it in same component 
        }
        else if (rank[parent_v] > rank[parent_u])
        {
            parent[parent_u] = parent_v;   // Merge it in same Component 
        }
        else
        {
            parent[parent_u] = parent_v; // You can do vice versa also
            rank[parent_v]++;
        }
    }
};

int main()
{
    int n = 7; // Let's assume 7 nodes (0 to 6)
    vector<int> parent(n);
    vector<int> rank(n);

    Solution s;
    s.makeSet(parent, rank, n);

    // Union operations
    int u1 = 1, v1 = 2;
    s.findUnionByRank(u1, v1, parent, rank);

    int u2 = 2, v2 = 3;
    s.findUnionByRank(u2, v2, parent, rank);

    int u3 = 4, v3 = 5;
    s.findUnionByRank(u3, v3, parent, rank);

    int u4 = 6, v4 = 5;
    s.findUnionByRank(u4, v4, parent, rank);

    // Now let's check if two nodes belong to the same component
    int a = 3, b = 1;
    if (s.findParent(parent, a) == s.findParent(parent, b))
        cout << a << " and " << b << " are in the same set.\n";
    else
        cout << a << " and " << b << " are in different sets.\n";

    int c = 3, d = 5;
    if (s.findParent(parent, c) == s.findParent(parent, d))
        cout << c << " and " << d << " are in the same set.\n";
    else
        cout << c << " and " << d << " are in different sets.\n";

    // Optional: Print final parent array
    cout << "\nParent Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << parent[i] << " ";
    }
    cout << endl;

    return 0;
}
