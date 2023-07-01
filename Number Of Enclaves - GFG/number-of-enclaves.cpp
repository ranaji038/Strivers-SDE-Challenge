//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    
        void dfs(int row,int col ,  vector<vector<int>> &vis, vector<vector<int>> &board){
        vis[row][col] = 1;
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        for(int i = 0 ; i < 4 ; i++){
            int nrow = row + drow[i] ;
            int ncol = col + dcol[i];
        
if(nrow >= 0  && nrow < vis.size() && ncol >=0 && ncol <vis[0].size() && vis[nrow][ncol]==0 && board[nrow][ncol] == 1){
        dfs(nrow,ncol,vis,board);                            
            }
            
        }
        
    } 
  public:
    int numberOfEnclaves(vector<vector<int>> &board) {
             int n = board.size();
        int m = board[0].size();
            
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        // Traversing the first row and last row
         for(int i =0  ; i < m ;i++){
            
            if(!vis[0][i] && board[0][i] == 1){
                    dfs(0,i,vis,board);
            }
            
            if(!vis[n-1][i] && board[n-1][i] == 1){
                    dfs(n-1,i,vis,board);
            }
            
    }
        // Traversing the first nd last colmn
        for(int i = 0 ; i < n ;i++){
                if(!vis[i][0] && board[i][0]== 1){
                        dfs(i,0,vis,board);
                }
                
                if(!vis[i][m-1] && board[i][m-1] == 1){
                        dfs(i,m-1,vis,board);
                }
        }
        int count = 0;
        // Changing the board
        for(int i = 0 ; i< n ; i++){
        for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && board[i][j] == 1)count++;
        }
                
        }     
            return count; // Code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends