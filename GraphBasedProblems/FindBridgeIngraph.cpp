class Solution {
public:
    int timer = 1;

    void dfs(int node,int parent,vector<int>adj[],vector<int>&vis,vector<int>&tin,vector<int>&low,vector<vector<int>>&bridges)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto it:adj[node])
        {
            if(it == parent)continue;
            if(!vis[it])
            {
                dfs(it,node,adj,vis,tin,low,bridges);
                low[node] = min(low[node],low[it]);
                if(low[it] > tin[node])
                {
                    bridges.push_back({it,node});

                }
            }
            else
            {
                low[node] = min(low[node],low[it]);
            }

        }
    }



    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n);
       vector<int>tin(n),low(n);
        vector<vector<int>>bridges;
        dfs(0,-1,adj,vis,tin,low,bridges);

        return bridges;
    }
};