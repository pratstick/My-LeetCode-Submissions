class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26] = {};
        int len = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;

            while (freq[s[i] - 'a'] > 2) {
                freq[s[start] - 'a']--;
                start++;
            }

            len = max(len, i - start + 1);
        }

        return len;
    }
};