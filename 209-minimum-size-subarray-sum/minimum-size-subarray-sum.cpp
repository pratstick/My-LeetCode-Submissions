class Solution {
public:
    bool isPossible(int target, vector<int>& nums, int len) {
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
        }
        if (sum >= target) return true;
        for (int i = len; i < nums.size(); i++) {
            sum += nums[i];
            sum -= nums[i - len];
            if (sum >= target)
                return true;
        }
        return false;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n;
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isPossible(target, nums, mid)) {
                ans = mid;
                right = mid - 1; // Try smaller length
            } else {
                left = mid + 1; // Try larger length
            }
        }
        return ans;
    }
};