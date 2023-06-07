class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
            vector<vector<int>> ans;
            int n = intervals.size();
            
            // Full BRute FOrce TC : O(nlogn) + O(2n) ;
            
//             sort(intervals.begin() , intervals.end());
        
//             for(int i = 0 ; i < n ; i++){
//                    int start = intervals[i][0];
//                    int end = intervals[i][1];
               
//                 if(!ans.empty() && end <= ans.back()[1] ) continue;
                  
//                 for(int j = i + 1 ; j < n ; j++){
                        
//                         if(intervals[j][0] <= end){
//                                 //overlap ho rha hai
//                                 end = max(end,intervals[j][1]);
//                         }else{
//                                 break;
//                         }
                        
//                 }
                    
                    
//         ans.push_back({start,end}); 
                    
//             }
            
            // O(nlogn) + O(n) approch
            
            sort(intervals.begin() , intervals.end());

            for(int i = 0 ; i < n ; i++){
                    
                   int start = intervals[i][0];
                   int end = intervals[i][1];
               
                if(ans.empty())  ans.push_back({start,end});
                   else{
                           
                            
                        if(ans.back()[1] >= start ){
                                //overlap ho rha hai
                               ans.back()[1] = max(end,ans.back()[1]);
                        }else{
                               ans.push_back({start,end});  
                        }
                        
                            
                           
                   }
                  
       
                        
                }
                    
                    
           
                    
                    
                    
                    
            
            
            return ans;
            
            
    }
};