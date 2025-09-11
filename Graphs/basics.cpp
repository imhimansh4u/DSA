// Implementation of graphs using adjacency list
#include <iostream>
#include <map>
#include <list>
#include <unordered_map>
using namespace std;
template <typename T>
class graph
{
public:
    unordered_map<T, list<T>> adj;
    void addEdge(T u, T v, bool direction)
    {
        // direction = 0 // is undirected graph
        // direction = 1 // is directed graph

        // create an edge from u to v
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printAdjacencyList() // Time Complexity: O(V + E)  , V is (keys in the map) (nodes) and E = total number of edges
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;                                     // no. of nodes
    cout << "Enter the no. of nodes " << endl; // here in this case it is useless
    cin >> n;
    int m; // no. of edges
    cout << "Enter the no. of edges " << endl;
    cin >> m;
    graph<int> g1;
    cout << "Now list out all the edges" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // here creating a undirected graph
        g1.addEdge(u, v, 0);
    }
    // printing the graph
    g1.printAdjacencyList();
    return 0;
}