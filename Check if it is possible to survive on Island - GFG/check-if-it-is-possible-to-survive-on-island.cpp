//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        if(N < M) return -1;
        
        long long foodreq = S*M;
        
        if(S >= 7){
            if(N*6 < M*7) return -1; 
        }
        
        if(foodreq%N == 0)
        return foodreq/N;
        
        else return 1 + foodreq/N;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends