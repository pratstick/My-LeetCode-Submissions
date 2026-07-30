class Solution {
private:
    long long timeFinish(int t, vector<int>& nums) {
        long long time = 0;
        for (int num : nums) {
            time += (num + (long long)t - 1) / t;
        }
        return time;
    }

public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long time = timeFinish(mid, nums);

            if (time <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        return ans;
    }
};