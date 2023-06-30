class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        	    int  n = grid.size();
	    int   m = grid[0].size();
	    
	    vector<vector<int>> vis(n,vector<int>(m,0));
	   vector<vector<int>> dist(n,vector<int>(m,0));
        
        queue<pair<int,pair<int,int>>> q;
        
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0){
                    vis[i][j] = 1;
                q.push({0,{i,j}});
                }
            }
        }
        
        while(!q.empty()){
            
            int distance = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            q.pop();
            
            dist[row][col] = distance;
            
            int rowd[] = {0,-1,0,1};
            int cold[] = {-1,0,1,0};
            for(int i = 0 ; i<4 ;i++){
                
                int nrow = row + rowd[i];
                int ncol = col + cold[i];
                
                if(nrow >=0 && nrow <n && ncol >=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({distance + 1 , {nrow,ncol}});
                }
                
                
            }
            
            
            
            
        }
        
        
        return dist;
	    
    }
};