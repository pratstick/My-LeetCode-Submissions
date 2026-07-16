class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> next(n + 1, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            vector<int> curr(n + 1, 0);

            for (int prevInd = ind - 1; prevInd >= -1; prevInd--) {

                int notTake = next[prevInd + 1];

                int take = 0;
                if (prevInd == -1 || nums[ind] > nums[prevInd])
                    take = 1 + next[ind + 1];

                curr[prevInd + 1] = max(take, notTake);
            }

            next = curr;
        }

        return next[0];
    }
};