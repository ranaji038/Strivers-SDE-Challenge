//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp(Job a, Job b){
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);
        int maxidead = 0;
        for(int i = 0 ; i < n ;i++){
            maxidead = max(maxidead , arr[i].dead);
        }
        vector<int> d(maxidead + 1 , -1);
        int cnt = 0;
        int maxprofit = 0;
        for(int i = 0 ; i < n ;i++){
            
             int id = arr[i].id;
             int deadline = arr[i].dead;
             int profit  = arr[i].profit;
             
             for(int k = deadline ; k > 0 ; k--){
                 if(d[k] == -1){
                     cnt++;
                     maxprofit += profit;
                     d[k] = id;
                     break;
                 }
             }
            
            
        }
        
        vector<int> ans;
        ans.push_back(cnt);
        ans.push_back(maxprofit);
        
        return ans;
        
        
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends