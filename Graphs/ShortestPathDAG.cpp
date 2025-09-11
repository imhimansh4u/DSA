/*     TASK - >> compute the shortest path in a DAG ( directed acyclic graph) using topological sort and relaxation
 */

// T.C. -> Total: O(V + E)
// DO a DRY RUN TO GET THE ANSWER AND UNDERSATND THE CODE
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;
class Solution
{
public:
    void solve(int node, unordered_map<int, list<pair<int, int>>> &adj, unordered_map<int, bool> &visited, stack<int> &st)
    {
        visited[node] = true;
        for (auto neighbour : adj[node])
        {
            int n = neighbour.first;
            if (!visited[n])
            {
                solve(n, adj, visited, st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        // code here
        unordered_map<int, list<pair<int, int>>> adj;
        // for visited
        unordered_map<int, bool> visited;
        stack<int> st;
        // create the adjacency list
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back(make_pair(v, weight));
        }
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                solve(i, adj, visited, st);
            }
        }
        vector<int> ans(V, INT_MAX);
        ans[0] = 0; // bcs here 0 is the source node
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            if (ans[top] == INT_MAX)
            {
                continue;
            }
            else
            {
                for (auto el : adj[top])
                {
                    int n = el.first;
                    int weight = el.second;
                    int newDist = ans[top] + weight;
                    if (newDist < ans[n])
                    {
                        ans[n] = newDist;
                    }
                }
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == INT_MAX)
            {
                ans[i] = -1;
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}

// THis is useful in only  DAG ,
// Also this works because , we are using topological sort order for the nodes to be visited , which allows us to compute each node
// Only after their dependencies are proceeded

// Time Complexity is -> O(V+E) -> linear and very fast