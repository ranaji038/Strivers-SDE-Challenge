//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    
    vector<int> ans;
    int l = 0 , r = n-1;
    int start = -1 , end = -1;
    while(l<=r){
        int mid = (l +r )/2;
        
        if(arr[mid] == x){
            start = mid;
            r = mid - 1;
            
        }else if(arr[mid] >x){
            r = mid -1;
        }else l = mid + 1;
    }
    
    l= 0;
    r = n-1;
       while(l<=r){
        int mid = (l + r)/2;
        
        if(arr[mid] == x){
            end = mid;
            l = mid + 1;
            
        }else if(arr[mid] >x){
            r = mid -1;
        }else l = mid + 1;
    }
    
    ans.push_back(start);
    ans.push_back(end);
    
    return ans;
    
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends