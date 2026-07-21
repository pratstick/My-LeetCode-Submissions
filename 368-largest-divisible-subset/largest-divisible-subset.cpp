class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return {};
        sort(nums.begin(), nums.end());
        int maxLen = 0;
        int lastIndex = -1;
        vector<int> dp(n, 1);
        vector<int> parent(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && dp[i] < dp[prev] + 1) {
                    dp[i] = dp[prev] + 1;
                    parent[i] = prev;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }
        vector<int> ans;
        int i = lastIndex;
        while (parent[i] != i) {
            ans.push_back(nums[i]);
            i = parent[i];
        }
        ans.push_back(nums[i]);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
