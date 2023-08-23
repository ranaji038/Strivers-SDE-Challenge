//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    long long int fun(int ind ,int coins[], int sum, vector<vector<long long>> &dp) {
     
     
     if(ind == 0){
        //  if(sum == 0) return 1;
         
         if(sum%coins[0] == 0) return 1;
         else return 0;
     }
     if(dp[ind][sum] != -1) return dp[ind][sum];
     
     long long int nottake = fun(ind-1,coins,sum,dp);
     long long int take = 0;
     if(coins[ind] <= sum){
         take = fun(ind , coins , sum - coins[ind],dp);
     }
     
     return dp[ind][sum] = take + nottake;
        
        
    }
    
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long>> dp(N , vector<long long>(sum + 1 , -1));
        return fun(N-1,coins,sum,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends