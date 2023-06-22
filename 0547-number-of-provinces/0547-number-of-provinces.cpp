class Solution {
public:
      void dfs(int node , vector<int> adj[] , vector<int> &vis){
              vis[node] = 1;
              for(auto it : adj[node]){
                      if(!vis[it]){
                              vis[it] = 1;
                              dfs(it,adj,vis);
                      }
              }
      }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
            int n = isConnected.size();
            
            vector<int> adj[n + 1];
            
            for(int i = 0 ; i < n ; i++){
                    for(int j = 0 ; j < n ; j++){
                            if(isConnected[i][j] == 1 && i!=j){
                                    adj[i+1].push_back(j+1);
                            }
                    }
            }
            
            // for(int i = 0 ; i <= n ; i++){
            //         cout<<i<<": ";
            //           for(auto it: adj[i]){
            //         cout<<it<<" ";
            // }
            //         cout<<endl;
            // }
            
            int cnt = 0;
            vector<int> vis(n+ 1, 0);
            for(int i = 1 ; i <= n ; i++){
                    if(!vis[i]){
                            cnt++;
                            dfs(i , adj , vis);
                    }
            }
          
            
           return cnt;
            
    }
};