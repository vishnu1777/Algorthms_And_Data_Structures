void dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&st){
	    vis[node] = 1;
	    
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,adj,vis,st);
	        }
	    }
	    st.push(node);
	}
	stack<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>st;
	    
	    vector<int>ans;
	    vector<int>vis(V);
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	        }
	    }
	    
	    
        return st;
	}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<int>adj[n];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
    }

    vector<int>dis(n,1e9);

    stack<int>st = topoSort(n, adj);
    vector<pair<int,int>>adjT[n];
     for(auto it:edges){
        adjT[it[0]].push_back({it[1],it[2]});
    }
    dis[0] = 0;
    while(!st.empty()){
        auto node = st.top(); st.pop();
        
        for(auto it:adjT[node]){
            int adjNode = it.first;
            int edw = it.second;
            if(dis[node]+edw < dis[adjNode]){
                dis[adjNode] = dis[node]+edw;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dis[i] == 1e9)dis[i] = -1;
    }
    return dis;



}
