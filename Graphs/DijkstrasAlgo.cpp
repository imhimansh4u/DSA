// Here is the Dijkstras algorithm for directed weighted graphs (The task is to find the minimum distance of each node from the src node)
#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <list>
using namespace std;

/*
Time Complexity: O(E log V)
Space Complexity: O(V + E)

✅ Explanation (optional):

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





// Time complexity -> O((V+E)log(V))      // log(V) is due to insertion and deletion of elements in the set

// THe process of reducing the cost to each node , in each step is called relaxation