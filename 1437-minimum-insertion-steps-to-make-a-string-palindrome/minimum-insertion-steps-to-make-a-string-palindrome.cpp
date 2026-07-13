class Solution {
private:
    int lcs(const string& str1, const string& str2) {
        int m = str1.size();
        int n = str2.size();

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        return prev[n];
    }

    int longestPalinSubseq(string s) {
        string reversed(s.rbegin(), s.rend());
        return lcs(s, reversed);
    }

public:
    int minInsertions(string s) { return s.size() - longestPalinSubseq(s); }
};