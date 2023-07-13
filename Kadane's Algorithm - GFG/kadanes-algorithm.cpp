//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long ans = INT_MIN , curr = 0;
        for(int i = 0 ; i < n ;i++){
            curr += arr[i];
            if(curr < 0) curr =0;
            ans = max(curr,ans);
            
        }
        if(ans == 0){
            int mini = INT_MIN;
            for(int i = 0 ; i < n ;i++){
                mini = max(mini , arr[i]);
            }
            return mini;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends