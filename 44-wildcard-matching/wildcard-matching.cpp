
class Solution {
private:
    bool helper(int i, int j, const string& str, const string& pat, vector<vector<int>>& dp) {
        
        if (i < 0 && j < 0) return true;
        if (i >= 0 && j < 0) return false;
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (pat[k] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];


        if (str[i] == pat[j] || pat[j] == '?') {
            return dp[i][j] = helper(i - 1, j - 1, str, pat, dp);
        }

        if (pat[j] == '*') {
            return dp[i][j] = helper(i, j - 1, str, pat, dp) || helper(i - 1, j, str, pat, dp);
        }

        return dp[i][j] = false;
    }
    
public:
    bool isMatch(string str, string pat) {
        int n = str.length();
        int m = pat.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return helper(n - 1, m - 1, str, pat, dp);
    }
};