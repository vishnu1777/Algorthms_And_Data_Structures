void createAdj(vector<int>adj[],int n,vector<vector<int>>&edge){
    for(auto it:edge){
        int u = it[0],v = it[1], edw = it[2];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}