/*You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and
if it is unreachable to reach any vertex, then return -1 for that vertex.*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    // BFS function that fills distance vector from the source
    void BFS(int src, vector<vector<int>> &adj, vector<int> &dist)
    {
        queue<int> q;
        q.push(src);
        dist[src] = 0; // distance to self is 0

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto neighbour : adj[node])
            {
                if (dist[neighbour] == -1)
                { // not visited yet
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour);
                }
            }
        }
    }

    // Function to find shortest path distances from source node
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        int n = adj.size();
        vector<int> dist(n, -1); // -1 means unreachable from src
        BFS(src, adj, dist);
        return dist;
    }
};
int main()
{

    return 0;
}