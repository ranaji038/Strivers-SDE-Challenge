class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
            if(n==0) return 0;
//            sort(nums.begin() , nums.end());
//             int longest = 1 , cnt = 0 , lastsmall = INT_MIN;
//             for(int i = 0 ; i< n ;i++){
                    
//                     if(nums[i] - 1 == lastsmall){
//                     cnt++;
//                     lastsmall = nums[i];
//             }else if(lastsmall != nums[i]){
//                     cnt = 1;
//                     lastsmall = nums[i];
//             }
            
//             longest = max(longest,cnt);
//     }
//                         return longest;

            
            
            int longest = 1;
            unordered_set<int> st;
            for(int i = 0 ; i < n ; i++) st.insert(nums[i]);
            
            for(auto it : st){
                    
                    if(st.find(it-1) == st.end()){
                            int cnt = 1;
                            int x = it;
                            while(st.find(x+1) != st.end()){
                                    cnt++, x++;
                            }
                            longest = max(longest, cnt);
                    }
                    
                    
            }
            
            return longest;
            
            
            
            
            
            }
        
                    
                    
        
    
};