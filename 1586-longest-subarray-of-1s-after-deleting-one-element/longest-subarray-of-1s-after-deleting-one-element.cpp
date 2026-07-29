class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int countZero = 0;
        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                countZero++;
            }

            while (countZero > 1) {
                if (nums[start] == 0) {
                    countZero--;
                }
                start++;
            }
            maxLen = max(maxLen, i - start);
        }

        return maxLen;
    }
};