class Solution {
public:
    vector<vector<int>> dp;
    vector<int> prefix;

    int sum(int l, int r) {
        if (l == 0) return prefix[r];
        return prefix[r] - prefix[l - 1];
    }

    int solve(int l, int r) {
        if (l == r) return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        for (int i = l; i < r; i++) {
            int leftSum = sum(l, i);
            int rightSum = sum(i + 1, r);

            if (leftSum < rightSum) {
                ans = max(ans, solve(l, i) + leftSum);
            }
            else if (leftSum > rightSum) {
                ans = max(ans, solve(i + 1, r) + rightSum);
            }
            else {
                ans = max(ans,
                         max(solve(l, i), solve(i + 1, r))
                         + leftSum);
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        prefix.resize(n);
        prefix[0] = stoneValue[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stoneValue[i];
        }

        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1);
    }
};