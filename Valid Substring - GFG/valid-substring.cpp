//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int> st;
        st.push(-1);
        int n = s.size();
        int res = 0;
        for(int i = 0 ; i < n ; i++){
            
            if(s[i] == '('){
                st.push(i);
            }else{
               
                    st.pop();
                
                 if(!st.empty()){
                
                int curr = i - st.top();
                res = max(res,curr);
                 }else{
                     st.push(i);
                 }
                
            }
            
            
        }
        
        return res;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends