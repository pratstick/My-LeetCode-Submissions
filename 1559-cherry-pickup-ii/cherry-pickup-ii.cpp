class Solution {
private:
    int m, n;
    int helper(int row, int col1, int col2, vector<vector<int>>& matrix,
               vector<vector<vector<int>>>& dp) {
        if (col1 < 0 || col2 < 0 || col1 >= m || col2 >= m || row >= n)
            return 0;
        if (row == n - 1) {
            if (col1 == col2)
                return matrix[row][col1];
            else
                return matrix[row][col1] + matrix[row][col2];
        }
        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];
        int maxi = INT_MIN;
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                maxi =
                    max(maxi, helper(row + 1, col1 + j, col2 + k, matrix, dp));
            }
        }
        if (col1 == col2)
            return dp[row][col1][col2] = matrix[row][col1] + maxi;
        else
            return dp[row][col1][col2] =
                       matrix[row][col1] + matrix[row][col2] + maxi;
    }

public:
    int cherryPickup(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));
        return helper(0, 0, m - 1, matrix, dp);
    }
};