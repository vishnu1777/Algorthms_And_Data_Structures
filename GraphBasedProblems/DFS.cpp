class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<int>adj[],vector<int>&ans,vector<int>&vis)
    {
        vis[node] = 1;
        ans.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,ans,vis);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<int>vis(V);
        dfs(0,adj,ans,vis);
        return ans;
    }
};