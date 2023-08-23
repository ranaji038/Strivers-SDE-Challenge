//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int mod = 1e9 + 7;

    int fun(int n , int r ,vector<vector<int>> &dp){
       if (r == 0 || n == r)
    {
        return 1;
    }
    
    if(dp[n][r] != -1) return dp[n][r];
    
        return dp[n][r] = (fun(n - 1, r - 1,dp) + fun(n - 1, r,dp))%mod;
    
        
    }
    
    
public:
    int nCr(int n, int r){
        if(r > n) return 0;
     vector<vector<int>> dp(n+1 , vector<int> ( r+1 , -1));
     return fun(n,r,dp);
     
     
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends