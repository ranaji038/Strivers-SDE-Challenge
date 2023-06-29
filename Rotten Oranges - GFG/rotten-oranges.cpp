//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
            int n = grid.size();
        int m = grid[0].size();
           
            vector<vector<int>> vis(n,vector<int>(m,0));
            
            queue <pair<int , pair<int,int>>> q;
            int cntfresh = 0;
            for(int i = 0 ; i < n ; i++){
                    for(int j = 0 ; j < m ; j++){
                
                if(grid[i][j] == 2){
                        q.push({0,{i,j}});
                        vis[i][j] = 2;
                }
                          
                if(grid[i][j] == 1) cntfresh++;
                    
                    }
            }
            
            int time = 0;
            int cnt = 0;
            int drow[] = {-1,0,1,0};
            int dcol[] = {0,1,0,-1};
        
            while(!q.empty()){
                
                int r = q.front().second.first;
                int c = q.front().second.second;
                int  t = q.front().first;
                   
                    time = max(time ,t);
                 q.pop();
                    
                    for(int i = 0 ; i < 4 ; i++){
                        
                        int nrow = r + drow[i];
                        int ncol = c + dcol[i];
               
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol <m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                        
                            q.push({t+1 ,{nrow,ncol}});
                            vis[nrow][ncol] =2;
                        cnt++;
                }}
                    
                    
                    
                    
                    
                    
            }
            
            if(cnt != cntfresh) return -1;
            
            return time;
            
            
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends