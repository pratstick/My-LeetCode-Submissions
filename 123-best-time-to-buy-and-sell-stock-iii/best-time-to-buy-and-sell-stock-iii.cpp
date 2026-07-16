class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> next_dp(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int cap = 1; cap <= 2; cap++) {
                curr[1][cap] = max(-arr[ind] + next_dp[0][cap], next_dp[1][cap]);
                curr[0][cap] = max(arr[ind] + next_dp[1][cap - 1], next_dp[0][cap]);
            }
            next_dp = curr;
        }
        
        return next_dp[1][2];
    }
};