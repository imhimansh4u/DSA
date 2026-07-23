// Here is the Dijkstras algorithm for directed weighted graphs (The task is to find the minimum distance of each node from the src node)
#include <iostream>
#include <unordered_map>
#include <set>
#include<climits>
#include <vector>
#include <list>
using namespace std;

/*
Time Complexity: O(E log V)
Space Complexity: O(V + E)

 Explanation (optional):

E log V comes from inserting edges into a set (logarithmic operations for each of the E edge relaxations).

V + E space is used for the adjacency list and distance vector.
*/

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{
    // Code here
    // firstly make adjacency list
    unordered_map<int, vector<pair<int, int>>> adj; // pair.first is v and pair.second is d/s from u to v(or weight)
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back(make_pair(v, w));
    }
    // array to store the answer
    vector<int> ans(V, INT_MAX);  // ans will contain the minimum distance of each node from the Source Node
    ans[src] = 0;                 // common sense   // bcs dis from src to src is 0
    set<pair<int, int>> st;       // the first int will contain the distance from the src and the second is for the root itself
    st.insert(make_pair(0, src)); // bcs the distance from the src to src is 0
    while (!st.empty())           // Remeber the set will contain each element in sorted form , means the minimum distance root will be at the beginning
    {
        auto top = *st.begin(); // st.begin() gives a iterator to the first element of the set st  (and *st.begin() will give the element)
        st.erase(st.begin());   // understand
        int ds = top.first;     // current distance of that perticular node from src
        int node = top.second;
        for (int i = 0; i < adj[node].size(); i++)
        {
            int destination = adj[node][i].first;
            int destinationDis = adj[node][i].second;
            if ((ds + destinationDis) < ans[destination])
            {
                // also delete the old entry of distance 
                if(ans[destination] != INT_MAX){
                    st.erase({ans[destination],destination}); // This to avoid visiting the same node again and again
                }
                ans[destination] = ds + destinationDis;
                st.insert(make_pair(ans[destination], destination));
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> edges;
    int E; // the no. of edges present in the graph
    int V;
    int src;
    cout << "Enter the no. of vertices then the no. of edges and the src in the graph" << endl;
    cin >> V;
    cin >> E;
    cin >> src;
    cout << "The total no. of vertices are " << V << " It means that node from 0 to " << V - 1 << " are present" << endl;
    cout << "Now enter all the edges ,firstly enter the u then v and then weight" << endl;
    for (int i = 0; i < E; i++)
    {
        int u;
        int v;
        int w;
        vector<int> temp(3);
        cin >> u;
        cin >> v;
        cin >> w;
        temp[0] = u;
        temp[1] = v;
        temp[2] = w;
        if (u > V - 1 || v > V - 1)
        {
            cout << "Enter a valid edge" << endl;
        }
        edges.push_back(temp);
    }
    cout << "The minimum path from " << src << " to all the nodes are ::" << endl;
    vector<int> ans;
    ans = dijkstra(V, edges, src);
    for (int i = 0; i < V; i++)
    {
        cout << "The minimum distance from " << src << " to " << i << " is " << ans[i] << endl;
    }
    return 0;
}




/***                                    ALGORITHM
 * Algorithm
Initialize all vertices:
Set Distance[v] = ∞ for every vertex v.
Set Parent[v] = NIL for every vertex.
Set the source vertex distance:
Distance[S] = 0.
Create a Min-Priority Queue (Min-Heap) and insert the source vertex with distance 0.
Repeat until the priority queue becomes empty:
Remove the vertex u having the minimum distance from the priority queue.
If u has already been processed, skip it.
Otherwise, mark u as visited.
Relax all adjacent edges of vertex u:
For every adjacent vertex v of u, perform the relaxation step.
Relaxation Step (Number-wise)

For every edge (u, v) with weight w:

Check whether

Distance[u] + w < Distance[v]
If the condition is true:

Update

Distance[v] = Distance[u] + w

Set

Parent[v] = u
Insert (or update) vertex v in the Min-Priority Queue with its new distance.
Otherwise:
Do nothing.
Repeat the relaxation process for every adjacent vertex of u.
Continue the Algorithm
Repeat Steps 4 and 5 until the priority queue becomes empty.
The Distance[] array now contains the shortest distance from the source vertex to every other vertex.
If the shortest path is required:
Start from the destination vertex.
Repeatedly follow the Parent[] array until the source vertex is reached.
Reverse the obtained sequence to get the shortest path.
Pseudocode
DIJKSTRA(G, S)

1. for each vertex v in G
       Distance[v] = ∞
       Parent[v] = NIL

2. Distance[S] = 0

3. Insert (0, S) into Min-Heap

4. while Min-Heap is not empty

       u = Extract-Min()

       if u is already visited
            continue

       Mark u as visited

       for every adjacent vertex v of u

            // Relaxation
            if Distance[u] + Weight(u,v) < Distance[v]

                 Distance[v] = Distance[u] + Weight(u,v)

                 Parent[v] = u

                 Insert (Distance[v], v) into Min-Heap

5. Return Distance[] and Parent[]
Relaxation Formula

For every edge (u, v):

If Distance[u]+Weight(u,v)<Distance[v]
	​


then update

Distance[v]=Distance[u]+Weight(u,v)
	​


and

Parent[v]=u
	​

Time Complexity
Using Adjacency Matrix: O(V
2
)
Using Adjacency List + Binary Min Heap: O((V+E)logV)
Using Fibonacci Heap: O(E+VlogV)
Space Complexity
Distance array: O(V)
Parent array: O(V)
Visited array: O(V)
Min-Heap: O(V)

Overall Space Complexity: O(V)
 * 
 * 
 * 
 * 
 */
// Time complexity -> O((V+E)log(V))      // log(V) is due to insertion and deletion of elements in the set

// THe process of reducing the cost to each node , in each step is called relaxation