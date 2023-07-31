//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    
    bool checkforthis(int d , vector<int> &stalls,int k){
        int n = stalls.size();
        k--;
        int prev = stalls[0];
        for(int i = 1 ; i < n ; i++){
            if(k==0) return true;
            
            if(stalls[i] - prev >= d){
                prev = stalls[i];
                k--;
            } 
            
        }
        
        if(k == 0) return true;
        return false;
        
    }
    
    int solve(int n, int k, vector<int> &stalls) {
    
    int maxi = 0 ;
    sort(stalls.begin() , stalls.end());
    for(auto it : stalls) maxi = max(maxi,it);
    
    
    int l = 0 , r = maxi;
    int ans = 0;
    while(l <=r){
        int mid = (l+r)/2;
        
        if(checkforthis(mid , stalls,k))
        {
            ans = mid;
            l = mid +1;
            
        }else{
            r = mid -1;
        }
        
        
    }
    
    
    return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends