class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<int> prev(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            vector<int> curr(n + 1, 0);
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                    continue;
                }
                int skip_str1 = (i >= 1) ? prev[j] : 0;
                int skip_str2 = (j >= 1) ? curr[j - 1] : 0;
                curr[j] = max(skip_str1, skip_str2);
            }
            prev = curr;
        }
        return prev[n];
    }
};