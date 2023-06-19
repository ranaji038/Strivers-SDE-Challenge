class Solution {
public:


   
   bool dfs(int sv , vector<int> adj[] , vector<int> &visited, int des){
           
           if(sv == des) return true;
                visited[sv] =1;
           for(auto it : adj[sv]){
                   if(it == des) return true;
                   if(!visited[it]){
                    if(dfs(it,adj,visited,des)) return true;  
                   }
           }
           
           return false;
           
           
   }    
        
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n] ;
         for(int i = 0; i < edges.size() ; i++){
                
                  int u = edges[i][0];
                   int v = edges[i][1];
                   
                   adj[u].push_back(v);
                adj[v].push_back(u);

                   
           }
            vector<int> visited(n,0);
         return dfs(source,adj,visited,destination) ;  
            
    }
};