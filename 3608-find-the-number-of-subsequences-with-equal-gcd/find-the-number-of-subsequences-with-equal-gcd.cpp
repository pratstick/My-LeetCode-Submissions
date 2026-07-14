class Solution {
public:
    const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>prev(201, vector<int>(201, 0));
        prev[0][0] = 1;
        for (int ind = 0; ind < n; ind++) {
            vector<vector<int>>curr(201, vector<int>(201, 0));
            for (int g1 = 0; g1 <= 200; g1++) {
                for (int g2 = 0; g2 <= 200; g2++) {

                    long long cur = prev[g1][g2];
                    if (cur == 0)
                        continue;

                    // Not take
                    curr[g1][g2] = (curr[g1][g2] + cur) % MOD;

                    // Take in seq1
                    int ng1 = (g1 == 0) ? nums[ind] : gcd(g1, nums[ind]);
                    curr[ng1][g2] = (curr[ng1][g2] + cur) % MOD;

                    // Take in seq2
                    int ng2 = (g2 == 0) ? nums[ind] : gcd(g2, nums[ind]);
                    curr[g1][ng2] = (curr[g1][ng2] + cur) % MOD;
                }
            }
            prev = curr;
        }

        long long ans = 0;
        for (int g = 1; g <= 200; g++)
            ans = (ans + prev[g][g]) % MOD;

        return ans;
    }
};