#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // t.c. of this function is in worst case O(N + l) , N is no of nodes and l is the length of node with largest degree
    // s.c. is O(N) , in worst case when for each node the recursion is called , or simply the function is called
    void DFSfunc(vector<vector<int>> &adj, vector<int> &isTraversed, vector<int> &ans, int node)
    {
        ans.push_back(node);
        isTraversed[node] = 1;
        for (int i : adj[node])
        {
            if (isTraversed[i] == 0)
            {
                DFSfunc(adj, isTraversed, ans, i);
            }
        }
    }
    vector<int> dfs(vector<vector<int>> &adj)
    {
        // Code here
        // initially mark all values at each index is 0
        vector<int> isTraversed(adj.size());
        // 0 -> if not traversed
        // 1 -> if traversed
        // to store the answer
        vector<int> ans;
        DFSfunc(adj, isTraversed, ans, 0); // here after passing the root node // or the starting node , all works are done in one go (if the full grpah is connected only then)
        return ans;
    }
};

int main()
{
    // create a adjacency list just to run the above code
    vector<vector<int>> adj = {{1, 2, 3}, {0, 2, 4}, {0, 1}, {0}, {1}}; // here V=5 //0,1,2,3,4
    cout << "Here is the dfs traversal of the given adjacency list or graph" << endl;
    Solution g1;
    // the answer will be stored in the following
    vector<int> ans;
    ans = g1.dfs(adj);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}