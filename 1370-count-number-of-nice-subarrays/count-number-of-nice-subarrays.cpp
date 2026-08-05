class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int left = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            k -= nums[right] % 2;

            while (k < 0) {
                k += nums[left] % 2;
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};