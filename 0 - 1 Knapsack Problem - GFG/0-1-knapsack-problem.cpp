//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
    int helper(int ind , int rem , int wt[] , int val[],vector<vector<int>> &dp){
        
        if(ind == 0 ){
            if(wt[0] <= rem) return val[0];
            else return 0;
        }
        
        if(dp[ind][rem] != -1 ) return dp[ind][rem];
        
        int nottake = 0 + helper(ind-1,rem,wt,val,dp);
        int take = 0;
        if(wt[ind] <= rem){
            take = val[ind] + helper(ind-1, rem- wt[ind] , wt,val,dp);
        }
        
        return dp[ind][rem] = max(take, nottake);
        
        
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int> (W + 1 , -1));
       return helper(n-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends