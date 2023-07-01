//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

private:

void dfs(int row,int col , vector<vector<int>> &vis, vector<vector<int>> &grid ,vector<pair<int,int>> &vs, int row0 , int col0){
    
    vis[row][col] = 1;
    
    vs.push_back({row - row0 , col - col0});
    
    int rowd[] = {-1,0,1,0};
    int cold[] ={0,1,0,-1};
     int n = grid.size();
        int m = grid[0].size();
    
    for(int i = 0 ; i < 4 ; i++){
        int nrow = row + rowd[i];
        int ncol = col + cold[i];
        
        if(nrow >=0 && nrow <n && ncol >=0 && ncol <m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
          dfs(nrow,ncol,vis,grid,vs,row0,col0);
        }
    }
    
    
    
}
    
    
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        set<vector<pair<int,int>>> st;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> vs;
                    dfs(i,j,vis,grid,vs,i,j);
                    st.insert(vs);
                }
            }
        }
        
        
    return st.size();    
        
        
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends