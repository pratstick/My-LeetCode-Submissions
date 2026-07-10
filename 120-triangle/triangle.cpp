class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        vector<int> prev(n,0);
        prev[0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            vector<int> curr(n,0);
            for (int j = 0; j < triangle[i].size(); j++) {
                int bottom = 1e9;
                if(j<triangle[i-1].size())bottom = prev[j];
                int br = 1e9;
                if (j >= 1) br = prev[j - 1];
                curr[j] = triangle[i][j] + min(bottom, br);
            }
            prev = curr;
        }
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, prev[i]);
        }
        return mini;
    }
};