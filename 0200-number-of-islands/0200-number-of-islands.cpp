class Solution {
public:
        void bfs( int row, int col , vector<vector<int>>&vis ,vector<vector<char>>& grid) {
                int n = grid.size();
                int m = grid[0].size();
                vis[row][col] = 1;
                queue<pair<int,int>> q;
                q.push({row,col});
                
                while(!q.empty()){
                        
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                        
                for(int i = -1 ; i <= 1 ; i++ ){
                int nrow = row + i;
                
                if(nrow >= 0 && nrow < n && grid[nrow][col] == '1' && !vis[nrow][col]){
                        vis[nrow][col] = 1;
                        q.push({nrow,col});
                }            
                        }
                        
                  for(int i = -1 ; i <= 1 ; i++ ){
                int ncol= col + i;
                
                if(ncol >= 0 && ncol < m && grid[row][ncol] == '1' && !vis[row][ncol]){
                        vis[row][ncol] = 1;
                        q.push({row,ncol});
                }            
                        }      
                        
                        
                }
             
        

                
        }
        
    int numIslands(vector<vector<char>>& grid) {

            int n = grid.size();
            int m = grid[0].size();
            int count = 0;
           
            vector<vector<int>> vis(n,vector<int>(m,0));
            
      
            
            for(int i  = 0  ; i < n ; i++){
                    for(int j = 0  ; j < m ; j++){
                            if(grid[i][j] == '1' && !vis[i][j]){
                                    bfs(i,j,vis,grid);
                                  count++;
                            }
                    }
            }
            
            return count;
    }
};