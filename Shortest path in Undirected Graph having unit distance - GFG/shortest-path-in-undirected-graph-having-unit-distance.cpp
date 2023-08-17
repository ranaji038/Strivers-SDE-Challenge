//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        
        for(int i =0 ;i < M ;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> dis(N,1e9);
        
        queue<pair<int,int>> q;
        q.push({src,0});
        dis[src] = 0;
        
        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second;
                q.pop();
            
            for(auto it : adj[node]){
                if(dis[it] > d + 1){
                    dis[it] = d+ 1;
                      q.push({it,dis[it]});
                }
              
            }
            
            
            
        }
        
        for(int i =0 ; i < N ; i++){
            if(dis[i] >= 1e9) dis[i] = -1;
        }
        
        return dis;
        
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends