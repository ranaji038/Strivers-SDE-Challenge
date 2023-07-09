class Solution {
public:
    int maxProduct(vector<int>& nums) {

            int n = nums.size();
            int maxi = INT_MIN;
            int prefix = 1, sufix =1;
            for(int i =0 ; i< n ;i++){
                
                    if(prefix == 0) prefix =1;
                    if(sufix == 0 ) sufix = 1;
                    prefix = prefix*nums[i];
                    sufix = sufix*nums[n-i-1];
                    maxi = max(maxi , max(prefix,sufix));
            }
            
            return maxi;
            
            
    }
};