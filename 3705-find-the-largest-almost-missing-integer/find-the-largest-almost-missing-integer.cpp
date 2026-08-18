class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        // When k = 1, return the largest element occurring exactly once
        if (k == 1) {
            int ans = -1;

            for (int x : nums) {
                if (freq[x] == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        int ans = -1;

        if (freq[nums[0]] == 1)
            ans = max(ans, nums[0]);

        if (freq[nums[n - 1]] == 1)
            ans = max(ans, nums[n - 1]);

        return ans;
    }
};