#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

vector<vector<int>> findBridges(vector<vector<int>> &edges,int V,int E){
    unordered_map<int,list<int>> adj;

    for(auto ele : edges){
        int u = ele[0];
        int v = ele[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> discoveryTime(V,-1);
    vector<int> lowTime(V,-1);
    vector<int> Parent(V,-1);
    unordered_map<int,bool> visited;
}
int main(){
    
    return 0;
}