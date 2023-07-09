class Solution {
public:
        void print(vector<int> temp){
                for(auto it : temp) cout<<it<<" ";
                cout<<endl;
        }
    vector<int> productExceptSelf(vector<int>& nums) {
                int n = nums.size();
            
            // O(1) Space ans
            
            vector<int> ans(n,1);
            int lp = 1;
            for(int i = 0 ; i < n ;i++){
                    ans[i] = lp;
                    lp *= nums[i];
            }
            // print(ans);
           
            int rp =1;
            for(int j = n-1 ; j>=0 ;j--){
                    ans[j] *= rp;
                    
                    rp *= nums[j];
            }
            print(ans);
            // for(int i =0 ;i < n ;i++)
        // ans[i] = left[i]*right[i];
            
            return ans;
            
            
            
            
            
            
            
            
            
            
            
            // BIG O(2n) Space
            
//             vector<int> left(n,1);
//             vector<int> right(n,1);
//             vector<int> ans(n,1);
//             left[0] = 1;
//             for(int i = 1 ; i < n ;i++){
//                     left[i] = left[i-1]*nums[i-1];
//             }
//             // print(left);
//             right[n-1] = 1;
            
//             for(int j = n-2 ; j>=0 ;j--){
//                     right[j] = right[j+1]*nums[j+1];
//             }
//             // print(right);
//             for(int i =0 ;i < n ;i++)
//         ans[i] = left[i]*right[i];
            
//             return ans;
            
            
            
    }
};