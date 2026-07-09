class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for (int row = 1; row < n; row++) {
            for (int col = 0; col < m; col++) {                
                int bottom = matrix[row - 1][col];
                int bl = (col - 1 >= 0) ? matrix[row - 1][col - 1] : INT_MAX;
                int br = (col + 1 < m) ? matrix[row - 1][col + 1] : INT_MAX;
                matrix[row][col] += min({bottom, bl, br});
            }
        }
        int mini = INT_MAX;
        for (int i = 0; i < m; i++) {
            mini = min(mini, matrix[n - 1][i]);
        }
        
        return mini;
    }
};