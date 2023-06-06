class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // First Transposeing the given matrix
        for(int i = 0 ; i < n ; i++){
            
            for(int j = i ; j<n ;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
            
        }
        
        //Reversing the rows
        for(int i = 0 ; i<n ; i++){
            
            reverse(matrix[i].begin() , matrix[i].end());
            
        }
        
    }
};