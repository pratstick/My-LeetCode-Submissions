class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int mini = INT_MAX;
        int curr_sum = 0;
        for (int i = 0; i < n; i++) {
            curr_sum += nums[i];
            while (curr_sum >= target) {
                int len = i - start + 1;
                mini = min(mini, len);
                curr_sum -= nums[start];
                start++;
            }
        }
        return (mini == INT_MAX) ? 0 : mini;
    }
};
