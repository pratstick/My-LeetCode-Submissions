class Solution {
private:
    int getScoreDiff(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == j) return nums[i];
        if (dp[i][j] != -1) return dp[i][j];

        // Player takes either the left element or the right element
        int takeLeft = nums[i] - getScoreDiff(i + 1, j, nums, dp);
        int takeRight = nums[j] - getScoreDiff(i, j - 1, nums, dp);

        return dp[i][j] = max(takeLeft, takeRight);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        // Player 1 wins if the max net difference is non-negative
        return getScoreDiff(0, n - 1, nums, dp) >= 0;
    }
};