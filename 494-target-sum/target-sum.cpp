class Solution {
private:
    const int MOD = 1e9 + 7;

public:
    int findTargetSumWays(vector<int>& arr,int diff) {
        int n = arr.size();
        int totalSum = 0;
        for (int num : arr) totalSum += num;
        
       if (abs(diff) > totalSum || (totalSum + diff) % 2 != 0) return 0;
        int target = (totalSum + diff) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        if (arr[0] == 0) dp[0][0] = 2; // Choose or don't choose 0
        else dp[0][0] = 1;             // Don't choose arr[0]

        if (arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1; // Choose arr[0]

        // Fill the DP table
        for (int ind = 1; ind < n; ind++) {
            for (int t = 0; t <= target; t++) {
                int notTake = dp[ind - 1][t];
                int take = 0;
                if (arr[ind] <= t) {
                    take = dp[ind - 1][t - arr[ind]];
                }
                dp[ind][t] = (take + notTake) % MOD;
            }
        }

        return dp[n - 1][target];
    }
};