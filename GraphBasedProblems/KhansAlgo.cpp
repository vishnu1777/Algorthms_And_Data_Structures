    #include<bits/stdc++.h>

    using namespace std;
    void khans(vector<int>adj[],vector<int>&vis,vector<int>&ans,int v){
	    vector<int>indegree(v);
	    for(int i=0;i<v;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<v;i++){
	        if(indegree[i] == 0){
	            q.push(i);
	            ans.push_back(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front(); q.pop();
	        
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0){
	                q.push(it);
	                ans.push_back(it);
	            }
	        }
	    }
	}

    int main(){
        return 0;
    }