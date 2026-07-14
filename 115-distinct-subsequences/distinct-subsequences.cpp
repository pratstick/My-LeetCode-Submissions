class Solution {
private:
    const int MOD = 1e9 + 7;

public:
    int numDistinct(string& s, string& t) {
        int m = s.size();
        int n = t.size();

        if (m < n) return 0;

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1])
                    dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }

        return dp[n];
    }
};