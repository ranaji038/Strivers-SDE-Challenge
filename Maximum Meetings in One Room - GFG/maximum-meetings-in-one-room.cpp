//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
 static bool cmp(pair<int,pair<int,int>> a , pair<int,pair<int,int>> b){
        return a.second.second < b.second.second;
    }
    
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        
    
        // Your code here
     vector<pair<int,pair<int,int>>> temp;
     
     for(int i = 0 ; i < N ; i++){
         temp.push_back({i+1,{S[i] , F[i]}});
     }
        
        sort(temp.begin(), temp.end(),cmp);
        
     vector<int> ans;
      ans.push_back(temp[0].first);
      int ansend = temp[0].second.second;
      for(int i = 1 ; i < N ; i++){
          if(temp[i].second.first > ansend){
              ans.push_back(temp[i].first);
              ansend = temp[i].second.second;
          }
      }
      
      sort(ans.begin(),ans.end());
      return ans;
        
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends