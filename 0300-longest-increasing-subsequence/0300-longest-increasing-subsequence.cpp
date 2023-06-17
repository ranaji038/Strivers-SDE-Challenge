class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
       vector<int>dp(n,1);
            for(int i =1 ; i < n ; i++){
                    for(int j = i-1 ; j>=0 ;j--){
                
                if(nums[j] >= nums[i]) continue;
                else {
                        
                        int possibleans = 1 + dp[j];
                        dp[i] = max(dp[i] , possibleans);
                        
                        
                        
                        
                        
                }
                            
                            
                            
                            
                            
                    }
            }
            int ans = 0;
            
            for(int i =0 ; i< n ; i++){
                    if(ans < dp[i]) ans = dp[i];
            }
            
            return ans;
            
    }
};