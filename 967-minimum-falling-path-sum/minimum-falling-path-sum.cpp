class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev = matrix[0];
        for (int row = 1; row < n; row++) {
            vector<int> curr(m,0);
            for (int col = 0; col < m; col++) {                
                int bottom = prev[col];
                int bl = INT_MAX;
                if(col-1>=0) bl = prev[col - 1];
                int br = INT_MAX;
                if(col+1<m) br = prev[col + 1];
                curr[col] = matrix[row][col] +  min({bottom, bl, br});
            }
            prev = curr;
        }
        int mini = INT_MAX;
        for (int i = 0; i < m; i++) {
            mini = min(mini, prev[i]);
        }
        
        return mini;
    }
};