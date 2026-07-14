class Solution {
public:
    const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(201, vector<int>(201, 0)));

        dp[0][0][0] = 1;

        for (int ind = 0; ind < n; ind++) {
            for (int g1 = 0; g1 <= 200; g1++) {
                for (int g2 = 0; g2 <= 200; g2++) {

                    long long cur = dp[ind][g1][g2];
                    if (cur == 0)
                        continue;

                    // Not take
                    dp[ind + 1][g1][g2] = (dp[ind + 1][g1][g2] + cur) % MOD;

                    // Take in seq1
                    int ng1 = (g1 == 0) ? nums[ind] : gcd(g1, nums[ind]);
                    dp[ind + 1][ng1][g2] = (dp[ind + 1][ng1][g2] + cur) % MOD;

                    // Take in seq2
                    int ng2 = (g2 == 0) ? nums[ind] : gcd(g2, nums[ind]);
                    dp[ind + 1][g1][ng2] = (dp[ind + 1][g1][ng2] + cur) % MOD;
                }
            }
        }

        long long ans = 0;
        for (int g = 1; g <= 200; g++)
            ans = (ans + dp[n][g][g]) % MOD;

        return ans;
    }
};