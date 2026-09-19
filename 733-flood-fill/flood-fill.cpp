class Solution {
    int m,n;
    int dr[4] = {0,-1,0,1};
    int dc[4] = {-1,0,1,0};
    bool isValid(int i, int j){
        if(i<0||j<0||i>=n||j>=m) return false;
        return true;
    }
    void dfs(int r, int c, vector<vector<int>>& image, int color, int startColor){
        image[r][c] = color;
        for(int i=0;i<4;i++){
            int row = r + dr[i];
            int col = c + dc[i];
            if(isValid(row,col) && image[row][col]==startColor){
                dfs(row,col,image,color,startColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image[0].size();
        n = image.size();
        int startColor = image[sr][sc];
        if (color == startColor)
            return image;
        dfs(sr,sc,image,color, startColor);
        return image;
    }
};