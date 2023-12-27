#include<bits/stdc++.h>
vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    queue<int>q;
    q.push(src);
    vector<int>dis(n,1e9);
    vector<int>adj[n];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    dis[src] = 0;

    while(!q.empty()){
        auto node = q.front(); q.pop();

        for(auto it:adj[node]){
            if(dis[node] + 1 < dis[it]){
                dis[it] = dis[node]+1;
                q.push(it);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dis[i] == 1e9)dis[i] = -1;
    }
    return dis;

}

int main(){
    return 0;
}