//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class disjointSet{
vector<int> rank , parent,size;
public :
    
    
    disjointSet(int x){
        rank.resize(x + 1);
        parent.resize(x + 1);
        size.resize(x+1);
        for(int i =0 ; i< x ;i++){
            parent[i] =  i;
            rank[i] = 0;
            size[i] = 1;
        }
        
    }
    int findUpar(int node){
        if(node == parent[node]) return node;
        
        return parent[node] = findUpar(parent[node]);
    }
    
    void unionbyrank(int x , int y){
        int parent_x = findUpar(x);
        int parent_y = findUpar(y);
        
        if(parent_x == parent_y) return ;
      
            if(rank[parent_x] < rank[parent_y]){
                
                parent[parent_x] = parent_y;
                
            }else if(rank[parent_x] > rank[parent_y]){
                 parent[parent_y] = parent_x;
            }else{
                   parent[parent_y] = parent_x;
                   rank[parent_x]++;
            }
        
        
        
        
     }
      void unionbysize(int x , int y){
        int parent_x = findUpar(x);
        int parent_y = findUpar(y);
        
        if(parent_x == parent_y) return ;
      
            if(size[parent_x] < size[parent_y]){
                
                parent[parent_x] = parent_y;
                size[parent_y] += size[parent_x];
                
            }else{
                   parent[parent_y] = parent_x;
                   size[parent_x] += size[parent_y];
            }
        
        
        
        
     }
    
    
    
    
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>> edges;
        for(int i = 0 ; i < V ;i++)
        for(auto it : adj[i]){
            int adjNode = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt,{node,adjNode}});
            
        }
        
       disjointSet ds(V);
       
       sort(edges.begin() , edges.end());
       
       int mst = 0;
       
       for(auto it : edges){
           int wt = it.first;
           int u = it.second.first;
           int v = it.second.second;
           
           if(ds.findUpar(u) != ds.findUpar(v)){
               mst += wt;
               ds.unionbysize(u,v);
           }
       }
       
       return mst;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends