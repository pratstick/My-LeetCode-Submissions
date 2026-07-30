class Solution {
private:
    // dis between cows is >= d
    bool canPlace(int d, const vector<int>& nums, int k, int n) {
        int count = 1;
        int last = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] - nums[last] >= d) {
                count++;
                last = i;
            }
        }
        if (count >= k)
            return true;
        return false;
    }

public:
    int maxDistance(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0;
        int high = nums[n - 1] - nums[0];
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlace(mid, nums, k, n)) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return ans;
    }
};