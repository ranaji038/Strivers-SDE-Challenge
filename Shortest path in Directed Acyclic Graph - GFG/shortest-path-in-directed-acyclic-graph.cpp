//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    void Topodfs(int node ,vector<pair<int,int>> adj[] , vector<int> &vis,stack<int> &st){
        vis[node] =1 ;
        for(auto it : adj[node]){
            if(!vis[it.first]){
                Topodfs(it.first,adj,vis,st);
            }
        }
        st.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        
        for(int i = 0 ; i < edges.size() ; i++){
            
            int from = edges[i][0];
            int to = edges[i][1];
            int wt = edges[i][2];
            
            adj[from].push_back({to,wt});
            
        }
        stack<int> st;
        vector<int> vis(N,0);
        for(int i =0 ; i < N ;i++){
            if(!vis[i]){
                Topodfs(i,adj,vis,st);
            }
        }
        
        vector<int> dis(N,1e9);
        dis[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            int d = dis[node];
            
            for(auto it : adj[node]){
                dis[it.first] = min(dis[it.first] , d + it.second);
            }
            
        }
        
        for(int i = 0 ; i < dis.size() ; i++){
            if(dis[i] >= 1e9){
                dis[i] = -1;
            }
        }
        
        return dis;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends