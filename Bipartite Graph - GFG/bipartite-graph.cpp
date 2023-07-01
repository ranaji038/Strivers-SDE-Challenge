//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool dfs(int start , vector<int>graph[] , vector<int>&colour,int parent){
        
        colour[start] = parent;
        
        for(auto it : graph[start]){
                if(colour[it] == -1){
                              if( dfs(it,graph,colour,!parent)== false) return false;
                        }else if( colour[it] == colour[start]){
                                return false;
                        }
        }
        return true;
        
}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int n = V;
	    vector<int> colour(n,-1);
     
            for(int i = 0 ; i < n ;i++){
                    if(colour[i] == -1){
                           if(dfs(i,adj,colour,0) == false)return false;
                            
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