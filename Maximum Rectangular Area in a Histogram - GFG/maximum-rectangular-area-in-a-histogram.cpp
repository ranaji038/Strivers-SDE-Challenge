//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    vector<long long> nextSmaller(long long arr[] , int n){
         vector<long long> ans(n);
        ans[n-1] = -1;
        stack<int> st;
        st.push(n-1);
        
        for(int i =n-2 ; i >= 0 ; i--){
            
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            
            if(st.size() == 0) ans[i] =-1;
            else{
                ans[i] = st.top();
                
            }
            
            st.push(i);
            
            
        }
        
        
        return ans;
    }
    
    
     vector<long long> prevSmaller(long long arr[] , int n){
         vector<long long> ans(n);
        ans[0] = -1;
        stack<int> st;
        st.push(0);
        
        for(int i =1 ; i <n ; i++){
            
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            
            if(st.size() == 0) ans[i] =-1;
            else{
                ans[i] = st.top();
                
            }
            
            st.push(i);
            
            
        }
        
        
        return ans;
    }
    
    
    
    
    
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> next(n);
        next = nextSmaller(arr,n);
        // for(auto it : next){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        vector<long long> prev(n);
        prev = prevSmaller(arr,n);
        //  for(auto it : prev){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        long long area = INT_MIN;
        for(int i =0 ; i < n ;i++){
            long long h= arr[i];
            if(next[i]  == -1) next[i] = n;
              long long b = next[i] - prev[i] -1;
            long long newA = h*b;
            area = max(area,newA);
        }
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends