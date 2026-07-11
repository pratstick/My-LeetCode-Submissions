class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int temp = INT_MAX;
            for (auto& c : coins) {
                if (c <= i && (dp[i - c] != INT_MAX))
                    temp = min(temp, (1 + dp[i - c]));
            }
            dp[i] = temp;
        }
        int ans = dp[amount];
        return (ans == INT_MAX) ? -1 : ans;
    }
};