// GOAL -> Find the minimum spanning tree
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include<queue>
#include<map>
using namespace std;
// Nodes are present from 1 to V

// Here the task is to return minimum spanning tree
vector<pair<pair<int, int>, int>> MST(int V, vector<vector<int>> &edges)
{
    // Firstly create the adjacency List
    unordered_map<int, list<pair<int, int>>> adj;
    int E = edges.size();
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    // Now we need mainly four things
    // Here i am taking 1 as root node
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> key;
    // Now a array to store the minimum weight
    vector<int> minWeight(V+1,INT_MAX);
    // 2,-> mst (To keep track that which nodes are included in the mst)
    vector<bool> mst(V + 1, false); // In starting no node is included
    // 3.-> parent (To keep track of the parent node for each node)
    vector<int> parent(V + 1, -1); // in starting sbka parent is -1
    minWeight[1] = 0;
    key.push({0,1});

    while(!key.empty())
    {
        auto mini = key.top();
        key.pop();
        int u = mini.second;
        mst[u] = true; // because this is now included in the mst
        // find the adjacent nodes of u
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < minWeight[v])
            {
                key.push({w,v});
                parent[v] = u;
                minWeight[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;

    // Now the parent array will Give parent of all the nodes
    for (int i = 2; i <= V; i++)
    {
        ans.push_back(make_pair(make_pair(parent[i], i), minWeight[i]));
    }
    return ans;
}

int main()
{

    return 0;
}







// NOTE-> using vector for storing key and then traversing it each time to find out the minimum element can cause T.C. -> O(n^2)
// thats why i will use priority queue (min Heap)

// By using vector for key -> T.C. -> O(n^2)
// By using priority queue -> T.C.-> O(ElogV) 
// s.c.- > O(V+E)