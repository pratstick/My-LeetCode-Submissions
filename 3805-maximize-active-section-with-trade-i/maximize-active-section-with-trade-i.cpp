class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            if (c == '1')
                ones++;
        s = "1" + s + "1";
        int i = 0;
        int n = s.size();
        // start ones
        while (i < n && s[i] == '1')
            i++;

        int leftZeroes = 0;
        while (i < n && s[i] == '0') {
            leftZeroes++;
            i++;
        }
        int ans = ones;
        while (i < n) {
            int midOnes = 0;
            while (i < n && s[i] == '1') {
                midOnes++;
                i++;
            }
            if (midOnes == 0)
                break;
            int rightZeroes = 0;
            while (i < n && s[i] == '0') {
                rightZeroes++;
                i++;
            }
            if(rightZeroes==0) break;
            ans = max(ans, ones+rightZeroes+leftZeroes);
            leftZeroes = rightZeroes;
        }
        return ans;
    }
};