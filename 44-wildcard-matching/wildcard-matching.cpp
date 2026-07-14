
class Solution {
   public:
    bool isMatch(string str, string pat) {
        int n = str.size();
        int m = pat.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; j++) {
            bool flag = true;
            for (int k = 1; k <= j; k++) {
                if (pat[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str[i-1] == pat[j-1] || pat[j-1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                else if (pat[j-1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }

        return dp[n][m];
    }
};