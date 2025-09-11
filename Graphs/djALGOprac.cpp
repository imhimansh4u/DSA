#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<set>  // insertion and deletion in set has log(n) T.C.


using namespace std;


vector<int> dijkstrasAlgo(int V,int E,vector<vector<int>> &edges,bool isDirected,int src){
    // firstly construct adj list 
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<E;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back(make_pair(v,w));
        if(!isDirected){
            adj[v].push_back(make_pair(u,w));
        }
    }

    // Now i need a set to keep the record of minimum distance from src node to a perticular node
    set<pair<int,int>> st; // here inside st , .first will give the weight and .second will give the destination node 
    vector<bool> isVisited(V,false);
    vector<int> dist(V,INT_MAX);
    dist[src] = 0;
    st.insert(make_pair(0,src));
    while(!st.empty()){
        pair<int,int> top = *st.begin();
        st.erase(st.begin());
        int nodeVal = top.first;
        int node = top.second;
        for(auto neighbour : adj[node]){
            if((neighbour.second+nodeVal)<dist[neighbour.first]){
                if(dist[neighbour.first] != INT_MAX){
                    st.erase(make_pair(dist[neighbour.first],neighbour.first));
                }
                dist[neighbour.first] = neighbour.second + nodeVal;
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }

    return dist;
    
}


int main(){

    return 0;
}