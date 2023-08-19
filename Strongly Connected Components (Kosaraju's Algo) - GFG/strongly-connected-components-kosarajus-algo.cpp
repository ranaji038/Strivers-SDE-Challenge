//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void topodfs(int node , vector<int> &vis, vector<vector<int>> &adj , stack<int> &st){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                topodfs(it,vis,adj,st);
            }
        }
        
        st.push(node);
    }
    
    void dfs(int node , vector<int> &vis , vector<int> adjnew[]){
         vis[node] = 1;
        
        for(auto it : adjnew[node]){
            if(!vis[it]){
                dfs(it,vis,adjnew);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        // vector<int> adj1[V];
        
        // for(int i =0 ;i < V ; i++){
        //     int u = adj[i][0];
        //     int v = adj[i][1];
        //     adj1[u].push_back(v);
        // }
        
        vector<int> vis(V,0);
        stack<int> st;
        
        for(int i =0 ; i < V ;i++){
            if(!vis[i]){
                topodfs(i,vis,adj,st);
            }
        }
        
       vector<int> adjnew[V];
       
       for(int i = 0 ; i < V ; i++){
           vis[i] = 0;
           for(auto it : adj[i]){
               adjnew[it].push_back(i);
           }
       }
       int cnt = 0;
       while(!st.empty()){
           int node = st.top();
            st.pop();
            if(!vis[node]){
                cnt++;
                dfs(node,vis,adjnew);
            }
       }
       
       return cnt;
        
        
        
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