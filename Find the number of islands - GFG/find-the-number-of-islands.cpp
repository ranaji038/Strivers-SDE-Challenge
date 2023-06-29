//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    void dfs(int row , int col , vector<vector<char>> &grid){
        
    
    if(row < 0 || col < 0 || row >= grid.size()  || col >= grid[0].size() ) return;
    
    if(grid[row][col] == '0' || grid[row][col] == '2') return;

    //   cout<<"row :"<<row<<"col :"<<col<<endl;
        grid[row][col] = '2';
        
        for(int i = - 1; i  <= 1 ; i++){
            for(int j = -1 ; j <= 1 ; j++){
                int nrow = row + i;
                int ncol = col + j;
                // if(nrow < 0 || nrow >= grid.size() || ncol < 0 || ncol >= grid[0].size() ) continue;
                // else
                dfs(nrow,ncol ,  grid);
            }
        }
        
    }
    
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(grid[i][j] == '1'){
                    dfs(i,j,grid);
                    cnt++;
                    // cout<<cnt<<endl;
                }
                
            }
        }
        
        return cnt;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends