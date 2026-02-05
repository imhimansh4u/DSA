//  Cycle Detection in Directed graphs    (Using Depth First Search)
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;
class Solution
{
public:
    bool Solve(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &DFSvisited,
               unordered_map<int, list<int>> &adj)
    {
        visited[node] = true;
        DFSvisited[node] = true;

        // traversing the neighbours
        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                bool isCycle = Solve(neighbour, visited, DFSvisited, adj);
                if (isCycle)
                    return true;
            }
            else if (visited[neighbour] && DFSvisited[neighbour])
            {
                return true;
            }
        }
        // jb function call se waps jao to--....
        DFSvisited[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // code here
        unordered_map<int, list<int>> adj;
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        // create a ds for track of node visited or not
        unordered_map<int, bool> visited;
        // create a ds for track of node is in call stack of the recursion or not
        unordered_map<int, bool> DFSvisited;
        // we are using for loop below bcs , the graph may be broken
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool isCycle = Solve(i, visited, DFSvisited, adj);
                if (isCycle)
                    return true;
            }
        }
        return false;
    }
};
int main()
{

    return 0;
}