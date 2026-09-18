class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid){
        grid[row][col] = '0';
        int r[4] = {0,-1,0,1};
        int c[4] = {-1,0,1,0}; 
        for(int i=0;i<4;i++){
            int nr = row + r[i];
            int nc = col + c[i];
            if(nr >=0 && nc >=0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc]=='1'){
                dfs(nr,nc,grid);
            }
        }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};