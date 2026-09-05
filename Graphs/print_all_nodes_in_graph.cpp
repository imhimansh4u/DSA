#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(int node, int par,
             vector<int> adj[],
             vector<int>& visited,
             vector<int>& parent,
             vector<int>& cycle) {

        visited[node] = 1;
        parent[node] = par;

        for(int nbr : adj[node]) {

            // Ignore parent edge
            if(nbr == par)
                continue;

            // Normal DFS
            if(!visited[nbr]) {

                if(dfs(nbr, node, adj, visited, parent, cycle))  // If one cycle found , return true , and dont go for other neighbours 
                    return true;
            }

            // Already visited and not parent -> cycle found
            else {

                cycle.push_back(nbr);

                int curr = node;

                while(curr != nbr) {
                    cycle.push_back(curr);
                    curr = parent[curr];
                }

                return true;
            }
        }

        return false;
    }

    vector<int> findCycle(int V, vector<int> adj[]) {

        vector<int> visited(V, 0);
        vector<int> parent(V, -1);
        vector<int> cycle;

        for(int i = 0; i < V; i++) {

            if(!visited[i]) {

                if(dfs(i, -1, adj, visited, parent, cycle))
                    break;
            }
        }

        return cycle;
    }
};