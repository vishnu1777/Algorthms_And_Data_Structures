#include<queue>
#include<bits/stdc++.h>
void createAdj(vector<pair<int,int>>adj[],int vertices,vector<vector<int>>&edge){
    for(auto it:edge){
        int u = it[0],v = it[1], edw = it[2];
        adj[u].push_back({v,edw});
        adj[v].push_back({u,edw});
    }
}
vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    vector<pair<int,int>>adj[vertices];
    
    createAdj(adj,vertices,edge);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,source});
    vector<int>dis(vertices,1e9);
    dis[source] = 0;


    while(!pq.empty()){
        auto it = pq.top(); pq.pop();
        int node = it.second;
        for(auto it:adj[node]){
            int adjNode = it.first;
            int edw = it.second;
            if(dis[node]+edw < dis[adjNode]){
                dis[adjNode] = dis[node]+edw;
                pq.push({dis[adjNode],adjNode});
            }
        }
    }
    return dis;

}

int main(){
    return 0;   
}