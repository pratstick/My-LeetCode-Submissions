class Solution {
private:
    int helper(int ind1, int ind2, const string& str1, const string& str2,
               vector<vector<int>>& dp) {
        if (ind1 < 0 || ind2 < 0) return 0;
        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
        int match = 0;
        if (str1[ind1] == str2[ind2]) {
            match = 1 + helper(ind1 - 1, ind2 - 1, str1, str2, dp);
        }
        int skip_str1 = helper(ind1 - 1, ind2, str1, str2, dp);
        int skip_str2 = helper(ind1, ind2 - 1, str1, str2, dp);
        return dp[ind1][ind2] = max({match, skip_str1, skip_str2});
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m-1,n-1,text1,text2,dp);        
    }
};