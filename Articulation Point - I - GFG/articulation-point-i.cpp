//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer = 1;
    void dfs(int node , int parent , vector<int> &vis , vector<int> adj[] , vector<int> &tin 
    , vector<int> &low , vector<int> & mark){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int childcnt = 0;
        for(auto it : adj[node]){
           
            if(it == parent ) continue;
            if(!vis[it]){
                dfs(it,node,vis,adj,tin,low,mark);
                low[node] = min(low[node] , low[it]);
                //articulate check
                
                if(low[it] >= tin[node] && parent != -1){
                    mark[node] = 1; 
                }
                 childcnt++;
                
            }else{
                low[node] = min(low[node], tin[it]);
            }
        }
        
        if(childcnt >1 && parent == -1) mark[node] = 1;
        
    }
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<int> vis(n,0);
        vector<int> tin(n,0);
        vector<int> low(n,0);
        vector<int> mark(n,0);
        for(int i = 0 ;i< n ;i++){
            if(!vis[i]){
                dfs(i,-1,vis,adj,tin,low,mark);
            }
        }
        
        vector<int> ans;
        for(int i = 0 ; i < n ;i++){
            if(mark[i])ans.push_back(i);
        }
        
        if(ans.size() == 0) return {-1};
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends