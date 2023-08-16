//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    bool bfs(int node , int colour , vector<int> adj[] , vector<int> &vis){
        queue<int> q;
        q.push(node);
        vis[node] = colour;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto it : adj[front]){
                if(vis[it] == -1){
                    vis[it] = !vis[front];
                    q.push(it);
                }else if( vis[it] == vis[front]){
                    return false;
                }
             }
            
            
        }
        return true;
    }

bool dfs(int start , int scol , vector<int> adj[] , vector<int> & vis){
    
    vis[start] = scol;
    
    for(auto it : adj[start]){
        if(vis[it] ==  -1){
            vis[it] = !scol;
           if( dfs(it, !scol , adj,vis) == false) return false ;
        }else if(vis[it] == vis[start]){
            return false;
        }
    }
    
    return true;
    
    
    
}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V,-1);
	    
	    for(int i = 0 ; i < V ; i++){
	        if(vis[i] == -1){
	            // node, colour , adjcency list , visted array
	           // if(bfs(i,0,adj,vis) == false) return false;
	           if(dfs(i,0,adj,vis )== false) return false;
	        }
	    }
	    
	    return true;
	    
	    
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends