// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u→v,
// vertex u comes before v in the ordering. There may be several topological orderings for a graph.

//Note: Topological Sorting for a graph is not possible if the graph is not a DAG.


#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//                                                 METHOD - 1 -> (Using DFS)
// Time Complexity: O(V + E)

// Space Complexity: O(V)

class Solution1
{
public:
    void dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, stack<int> &ansStack, int node)
    {
        visited[node] = true;
        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                dfs(adj, visited, ansStack, neighbour);
            }
        }
        ansStack.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        // firstly construct the adjacency list
        unordered_map<int, list<int>> adj;
        for (auto i : edges)
        {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }
        // ds for track of visited
        unordered_map<int, bool> visited;
        stack<int> ansStack; // in this stack our topological sort will be stored
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(adj, visited, ansStack, i);
            }
        }
        // to store answer
        vector<int> ans;
        while (!ansStack.empty())
        {
            ans.push_back(ansStack.top());
            ansStack.pop();
        }
        return ans;
    }
};

//                                                           METHOD - 2 -> USING BFS (KAHN'S ALGORITHM)

class Solution2
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        unordered_map<int, list<int>> adj;
        vector<int> InDegree(V, 0);
        for (auto i : edges)
        {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            InDegree[v]++;
        }
        queue<int> q;
        // push the elements in queue whose indegree is 0
        for (int i = 0; i < V; i++)
        {
            if (InDegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            for (auto neighbour : adj[frontNode])
            {
                InDegree[neighbour]--;
                if (InDegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}

