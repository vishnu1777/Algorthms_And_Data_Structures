class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&st){
	    vis[node] = 1;
	    
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,adj,vis,st);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>st;
	    
	    vector<int>ans;
	    vector<int>vis(V);
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	        }
	    }
	    
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};