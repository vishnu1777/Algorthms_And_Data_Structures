//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<vector<int>>&adj,stack<int>&st,vector<int>&vis){
	    vis[node] = 1;
	    
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,adj,st,vis);
	        }
	    }
	    st.push(node);
	}
	void dfs2(int node,vector<int>adj[],vector<int>&vis){
	    vis[node] = 1;
	    
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs2(it,adj,vis);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
       
        stack<int>st;
        vector<int>vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,st,vis);
            }
        }
        
        vector<int>adjT[V];
        for(int i=0;i<V;i++){
            vis[i] = 0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        int ssC = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                ssC++;
                dfs2(node,adjT,vis);
            }
        }
        return ssC;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends