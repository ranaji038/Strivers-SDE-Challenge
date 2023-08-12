//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        int min = 0 , max = 0;
        int cnt = 0;
        for(int i = 0 ; cnt < N  ; i++){
            min += candies[i];
            max += candies[N-1 -i];
           cnt = cnt + K + 1;
        }
        vector<int> ans(2);
        ans[0] = min;
        ans[1] = max;
        
        return ans;
        
        
        
    }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends