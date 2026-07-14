
class Solution {
   public:
    bool isMatch(string str, string pat) {
        int n = str.size();
        int m = pat.size();
        vector<bool> prev(m + 1, false);
        prev[0] = true;
        for(int j = 1; j <= m; j++) {
            bool flag = true;
            for (int k = 1; k <= j; k++) {
                if (pat[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }
        for (int i = 1; i <= n; i++) {
            vector<bool> curr(m + 1, false);
             for (int j = 1; j <= m; j++) {
                if (str[i - 1] == pat[j - 1] || pat[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                }

                else if (pat[j - 1] == '*') {
                    curr[j] = curr[j - 1] || prev[j];
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};