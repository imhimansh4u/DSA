// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// class Solution
// {
// public:
//     // t.c. is O(N+l)  // N is no. of nodes and l is no. of the edges with the largest degree
//     // s.c. is  O(N) , in worst case when every nodes should be stored in the queue
//     void BFSfunc(vector<vector<int>> adj, vector<int> &ans, vector<bool> &isTraversed, int node)
//     {
//         queue<int> q;
//         q.push(node);
//         isTraversed[node] = true;
//         while (!q.empty())
//         {
//             int frontNode = q.front();
//             q.pop();
//             ans.push_back(frontNode);
//             for (auto i : adj[frontNode])
//             {
//                 if (!isTraversed[i])
//                 {
//                     q.push(i);
//                     isTraversed[i] = true;
//                 }
//             }
//         }
//     }
//     // Function to return Breadth First Traversal of given graph.
//     vector<int> bfs(vector<vector<int>> &adj)
//     {
//         // Code here
//         vector<bool> isTraversed(adj.size()); // store the information that weather the node has been traveresed or not
//         // to store the answer
//         vector<int> ans;
//         // mark for all the nodes to be false initially
//         for (int i = 0; i < adj.size(); i++)
//         {
//             isTraversed[i] = false;
//         }
//         for (int i = 0; i < adj.size(); i++)
//         {
//             if (isTraversed[i] == false)
//             {
//                 BFSfunc(adj, ans, isTraversed, i);
//             }
//         }
//         return ans;
//     }
// };
// int main()
// {
//     // create a adjacency list just to run the above code
//     vector<vector<int>> adj = {{1, 2, 3}, {0, 2, 4}, {0, 1}, {0}, {1}}; // here V=5 //0,1,2,3,4
//     cout << "Here is the bfs traversal of the given adjacency list or graph" << endl;
//     Solution g1;
//     // the answer will be stored in the following
//     vector<int> ans;
//     ans = g1.bfs(adj);
//     for (int i : ans)
//     {
//         cout << i << " ";
//     }

//     return 0;
// }

#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<map>
using namespace std;

void solve(map<int, list<int>> &adj,vector<bool> &isVisited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto i : adj[node]){
            if(!isVisited[i]){
                q.push(i);
                isVisited[i] = true;
            }
        }
    }
}
vector<int> bfs(map<int, list<int>> &adj, int n)
{ // n here is the no. of nodes
    vector<bool> isVisited(n,false);
    vector<int> ans;

    for(auto p : adj){
        if(!isVisited[p.first]){
            solve(adj,isVisited,ans,p.first);
        }
    }
    return ans;
}
int main(){

    return 0;
}