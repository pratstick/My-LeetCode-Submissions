class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for (int row = 1; row < n; row++) {
            for (int col = 0; col < m; col++) {                
                int bottom = matrix[row - 1][col];
                int bl = INT_MAX;
                if(col-1>=0) bl = matrix[row - 1][col - 1];
                int br = INT_MAX;
                if(col+1<m) br = matrix[row - 1][col + 1];
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