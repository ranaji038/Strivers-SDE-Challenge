//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int fun(int coins[] , int m,int V, vector<vector<int>> &dp){
	    
	    if(m == 0){
	        if(V%coins[0] == 0) return V/coins[0];
	        
	        return 1e7;
	    }
	    if(dp[m][V] != -1) return dp[m][V];
	    
	    int nottake = fun(coins,m-1,V,dp);
	    int take = 1e7;
	    if(coins[m] <= V){
	        take = 1 + fun(coins,m , V-coins[m],dp);
	    }
	    
	    return dp[m][V] = min(take,nottake);
	    
	    
	    
	    
	}
	
	
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(M,vector<int>(V + 1 , -1));
	    int x =  fun(coins,M -1,V ,dp);
	    return x >= 1e7 ? -1 : x ;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends