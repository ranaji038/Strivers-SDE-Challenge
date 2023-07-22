class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
            int n = matrix.size();
            int m = matrix[0].size();
            vector<pair<int,int>> temp;
            for(int i = 0 ; i < n ; i++)
                    for(int j = 0 ; j < m ; j++){
                            if(matrix[i][j] == 0){
                                   temp.push_back({i,j});
                            }
                            
                            
                    }
            
             for(int i = 0 ; i < temp.size() ; i++){
                     pair<int,int> it = temp[i];
                     
                     for(int i = 0 ;i < n ; i++){
                             matrix[i][it.second] = 0;
                     }
                      for(int i = 0 ;i < m ; i++){
                             matrix[it.first][i] = 0;
                     }
             }
                            
                            
                    
            
            
            
    }
};