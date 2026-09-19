class Solution {
private:
    int m, n;

    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {-1, 0, 1, 0};

    bool isValid(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    void dfs(int r, int c, vector<vector<int>>& grid) {
        grid[r][c] = 0;

        for(int i = 0; i < 4; i++) {
            int row = r + dr[i];
            int col = c + dc[i];

            if(isValid(row, col) && grid[row][col] == 1) {
                dfs(row, col, grid);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for(int r = 0; r < n; r++) {
            if(grid[r][0] == 1)
                dfs(r, 0, grid);

            if(grid[r][m - 1] == 1)
                dfs(r, m - 1, grid);
        }

        for(int c = 0; c < m; c++) {
            if(grid[0][c] == 1)
                dfs(0, c, grid);

            if(grid[n - 1][c] == 1)
                dfs(n - 1, c, grid);
        }

        // Count remaining land
        int count = 0;

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                count += grid[r][c];
            }
        }

        return count;
    }
};