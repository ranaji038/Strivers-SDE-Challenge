class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
//         int row = matrix.size();
//         int col = matrix[0].size();
        
//         int start = 0;
//         int end = row*col -1;
//         int mid = start + (end-start)/2;
        
//         while(end>=start){
            
            
            
//             int element = matrix[mid/col][mid%col];
            
//             if(element==target)return 1;
//             else if(element < target){
//                 start = mid +1;
                
//             }else{
//                 end = mid -1;
//             }
            
//             mid = start + (end-start)/2;
//         }
        
//         return 0;
        

        // O(m+n) approch
         int row = matrix.size();
        int col = matrix[0].size();
        
        int rowindex = 0;
        int colindex = col - 1;
        
        while(rowindex < row && colindex >=0 ){
            
            int element = matrix[rowindex][colindex];
            
            if(element == target)return 1;
            else if(element <target)rowindex++;
            else colindex--;
            
        }
        
        return 0;
        
        
    }
};