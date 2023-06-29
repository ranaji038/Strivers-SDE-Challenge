class Solution {
public:
        void dfs(vector<vector<int>>& image, int sr, int sc, int color , int prevcolour) {
        
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;
                
                if(image[sr][sc] == color || image[sr][sc] != prevcolour) return ;
                
                image[sr][sc] = color;
                
                dfs(image,sr+1 , sc,color,prevcolour);
                dfs(image,sr , sc+1,color,prevcolour);
                dfs(image,sr-1 , sc,color,prevcolour);
                dfs(image,sr , sc-1,color,prevcolour);
              
                

                
                
                
        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
            dfs(image,sr,sc,color,image[sr][sc]);
            return image;
    }
};