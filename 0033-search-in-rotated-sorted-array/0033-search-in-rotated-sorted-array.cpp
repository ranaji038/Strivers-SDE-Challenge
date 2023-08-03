class Solution {
public:
    int search(vector<int>& nums, int target) {
        
            int n = nums.size();
            // if(n==1 ){
            //         if(nums[0] == target) return 0;
            //         else return -1;
            // }
        int pivotindex = -1;
            
            int l = 0 , r = nums.size() - 1;
            
            while(l<=r){
                    int mid = l - (l-r)/2;
                    
                    if(nums[mid] > nums[n-1]) l = mid + 1;
                    else r = mid -1;
                   
                    
                    
            }
            pivotindex = l;
           
            if(pivotindex == 0){
                    l = 0 , r = n-1;
                   while(l<=r){
                    int mid = l - (l-r)/2;
                    
                   if(nums[mid] == target) return mid;
                   else if(nums[mid] > target) r = mid -1;
                else l = mid +1;
                    
                    
            } 
            }else if(target >= nums[pivotindex] && target <= nums[n-1] ){
                    
               l = pivotindex , r = n-1;
                   while(l<=r){
                    int mid = l - (l-r)/2;
                    
                   if(nums[mid] == target) return mid;
                   else if(nums[mid] > target) r = mid -1;
                else l = mid +1;
                    
                    
            }       
                    
                    
            }else{
                l = 0 , r = pivotindex -1;
                   while(l<=r){
                    int mid = l - (l-r)/2;
                    
                   if(nums[mid] == target) return mid;
                   else if(nums[mid] > target) r = mid -1;
                else l = mid +1;
                    
                    
            }     
            }
           
            
            return -1;
            
            
    }
};