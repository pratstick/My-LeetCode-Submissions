class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 1)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        int p0 = nums[0];
        int p1 = max(nums[1], nums[0]);
        for (int i = 2; i < n; i++) {
            int curr = max(nums[i] + p0, p1);
            p0 = p1;
            p1 = curr;
        }
        return p1;
    }
};