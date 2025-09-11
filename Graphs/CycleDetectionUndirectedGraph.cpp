// Cycle detection in undirected graph
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;
// firstl using bfs method
bool BFSCycleCheck(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, int> &parent)
{
    visited[node] = true;
    queue<int> q;
    q.push(node);
    parent[node] = -1; // bcs src node ka koi parent nhi hota hai to hm apne mn se -1 le lete hai (bs aise hi)
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        // now look for the neighbours of the front Node
        for (auto neighbour : adj[frontNode])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
                q.push(neighbour);
            }
            else if (visited[neighbour] && parent[neighbour] != frontNode)
            {
                // it means that there is a loop present
                return true;
            }
        }
    }
    return false;
}
bool IsCyclePresent(int V, vector<pair<int, int>> &edges)
{
    // ds for the adjacecny list
    unordered_map<int, list<int>> adj;
    // firsly create a ds to track the visited
    unordered_map<int, bool> visited;
    // create a ds to keep track of the parent of the node
    unordered_map<int, int> parent;
    // create the adjacecncy list
    for (auto i : edges)
    {
        int u = i.first;
        int v = i.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // now if the graph is broken..
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bool isCycle = BFSCycleCheck(i, adj, visited, parent);
            if (isCycle)
                return true;
        }
    }
    return false;
}
int main()
{
    int V = 5;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {2, 3}, {3, 4}, {2, 4}};
    bool ans = IsCyclePresent(V, edges);
    if (ans)
        cout << "Yes the cycle is present";
    else
        cout << "No cycle is present";
    return 0;
}