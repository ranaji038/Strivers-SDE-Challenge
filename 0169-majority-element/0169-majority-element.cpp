class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
                int n = nums.size();
//         	unordered_map<int,int> mpp;

// 	for(int i = 0 ; i < n ; i++){
// 		mpp[nums[i]]++;

// 	}


// 	for(auto it : mpp){

// 		if(it.second > n/2) return it.first;
// 	}

//         return -1;    
            
            // Moores Voting ALgorithm
            int cnt = 0 ; int el;
           
            for(int i = 0 ; i < n ; i++){
                    if(cnt == 0){
                            el = nums[i];
                            cnt = 1;
                            
                    }else if(nums[i] == el) cnt++;
                    else cnt--;
            }
            
            return el;
            
    }
};