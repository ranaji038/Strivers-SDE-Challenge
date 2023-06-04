class Solution {
public:
        
        vector<int> givemerow(int n){
                
                vector<int> temp;
                long long ans = 1;
                temp.push_back(ans);
                
                for(int i = 1 ; i < n ; i++){
                        ans = ans*(n-i);
                        ans = ans/i;
                        temp.push_back(ans);
                }
                
                return temp;
                
                
        }
        
        
    vector<vector<int>> generate(int numRows) {
        
         vector<vector<int>>ans;
            int n = numRows;
            
         for(int i = 1 ; i <=n ; i++){
                 
                vector<int> temp = givemerow(i);
                 ans.push_back(temp);
         }
            
            return ans;
            
    }
};