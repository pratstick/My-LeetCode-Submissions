class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=1;i<=m;i++){
            for(int j = 1; j <= n; j++){
                int match = 0;
                if (text1[i-1] == text2[j-1]) {
                    match = 1 + dp[i-1][j-1];
                }
                int skip_str1 = (i>=1)?dp[i-1][j]:0;
                int skip_str2 = (j>=1)?dp[i][j-1]:0;
                dp[i][j] = max({match,skip_str1,skip_str2});
            }
        }
        return dp[m][n];      
    }
};