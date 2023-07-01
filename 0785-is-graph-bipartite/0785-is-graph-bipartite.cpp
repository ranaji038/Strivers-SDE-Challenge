class Solution {
public:
        
bool bfs(int start , vector<vector<int>>graph , vector<int>&colour){
        
        queue<int> q;
        q.push(start);
        colour[start] = 0;
        while(!q.empty()){
                int node = q.front();
                q.pop();
                
                for(auto it : graph[node]){
                        if(colour[it] == -1){
                                colour[it] = !colour[node];
                                q.push(it);
                        }else if( colour[it] == colour[node]){
                                return false;
                        }
                }
                
        }
        
 return true;       
        
        
}
bool dfs(int start , vector<vector<int>>graph , vector<int>&colour,int parent){
        
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
        
    bool isBipartite(vector<vector<int>>& graph) {
          int n = graph.size();
  
   
            vector<int> colour(n,-1);
     
            for(int i = 0 ; i < n ;i++){
                    if(colour[i] == -1){
                           if(dfs(i,graph,colour,0) == false)return false;
                            
                    }
            }
            
            return true;
         
            
            
            
    }
};