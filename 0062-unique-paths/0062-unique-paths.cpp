class Solution {
public: 
//         int fun(int i , int j , vector<vector<int>> &dp){
//                 if(i == 0 || j== 0) return 1;
                
//                 if(i <0 || j < 0) return 0;
                
//                 if(dp[i][j] != -1 )return dp[i][j];
                
                
//         return dp[i][j] = fun(i-1,j,dp) + fun(i,j-1,dp);
                
//         }
    int uniquePaths(int m, int n) {
        
//             vector<vector<int>>dp(m,vector<int>(n , -1));
            
//             // return fun(m-1,n-1,dp);
            
//             for(int i = 0 ; i < m ; i++){
//                     for(int j = 0 ; j < n ; j++){
                            
//                 if( i == 0 || j == 0) dp[i][j] = 1;
                
//              else   dp[i][j] = dp[i][j-1] + dp[i-1][j];
                            
//                     }
//             }
          
//             return dp[m-1][n-1];
            
            // Google method bus ncr ka khel
            
            int N = n+m-2;
            int r = m-1;
            double res = 1;
            for(int t = 1 ; t<=r ; t++){
                    res = res * (N-r + t) /t;
                    
            }
            return (int)res;
            
    }
};