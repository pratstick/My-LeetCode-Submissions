class Solution {
   private:
    int noOfWays(int row, int col, int m, int n, vector<vector<int>>& dp) {
        if (row == m - 1 && col == n - 1) return 1;
        if (row >= m || col >= n) return 0;
        if (dp[row][col] != -1) return dp[row][col];
        int right = 0;
        if (col + 1 < n) right = noOfWays(row, col + 1, m, n, dp);
        int down = 0;
        if (row + 1 < m) down = noOfWays(row + 1, col, m, n, dp);
        return dp[row][col] = right + down;
    }

   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return noOfWays(0, 0, m, n, dp);
    }
};