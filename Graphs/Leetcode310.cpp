/*
310. Minimum Height Trees

A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph
without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an
undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as
the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum
height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/

// CONCEPT -> Any Tree can have 1 or 2 centres and only centre elements Gives us the minimum Height Tree //
// Therefore , We will eliminate the leaf nodes of the Tree (i.e.-> Trees whose Degree is two) Until Remaining nodes>2

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (edges.size() == 0)
        {
            return {0};
        }
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        cout << "stage 1" << endl;
        queue<int> leaves;
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 1)
            {
                leaves.push(i);
            }
        }
        cout << "stage 2" << endl;
        int remainingNodes = n;
        while (remainingNodes > 2)
        {
            int leaf = leaves.size();
            remainingNodes -= leaf;
            for (int i = 0; i < leaf; i++)
            {
                int node = leaves.front();
                leaves.pop();
                for (int neighbour : adj[node])
                {
                    degree[neighbour]--;
                    if (degree[neighbour] == 1)
                    {
                        leaves.push(neighbour);
                    }
                }
            }
        }
        cout << "stage 3" << endl;
        vector<int> ans;
        while (!leaves.empty())
        {
            ans.push_back(leaves.front());
            leaves.pop();
        }
        return ans;
    }
};

int main()
{
    return 0;
}