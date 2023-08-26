//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    
	    vector<int> pos , neg;
	    
	    for(int i = 0 ; i < n ; i++){
	        if(arr[i] <0) neg.push_back(arr[i]);
	        else pos.push_back(arr[i]);
	    }
	    int pt = 0 , nt =0;
	    int i = 0 ;
	    for(; i < n && pt < pos.size() && nt < neg.size();i++){
	        if(i%2 == 0){
	            arr[i] = pos[pt];
	            pt++;
	        }else{
	            arr[i] = neg[nt];
	            nt++;
	        }
	        
	    }
	    
	    while(pt < pos.size()){
	        arr[i] = pos[pt];
	        pt++;
	        i++;
	    }
	    
	     while(nt < neg.size()){
	        arr[i] = neg[nt];
	        nt++;
	        i++;
	    }
	    
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends