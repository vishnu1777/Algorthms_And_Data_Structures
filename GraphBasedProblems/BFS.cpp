class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans)
    {
        vis[node] = 1;
        queue<int>q;
        q.push(node);
        ans.push_back(node);
        while(!q.empty())
        {
            int node = q.front();
           
            q.pop();
            
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    ans.push_back(it);
                    q.push(it);
                    vis[it] = 1;
                }
               
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       
        vector<int>ans;
        vector<int>vis(V);
        bfs(0,adj,vis,ans);
        return ans;
    }
};

int main(){
    return 0;
}