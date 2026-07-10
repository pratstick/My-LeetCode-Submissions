class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        unsigned long long lsum = 0;
        for (int x : nums) lsum += x;

        unsigned long long rprod = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            lsum -= nums[i];  
            if (lsum == rprod)  
                return i;
            if (rprod > lsum / nums[i])  
                break;

            rprod *= nums[i];  // Update from prod(nums[i+1...n-1]) -> prod(nums[i..n-1])
        }

        return -1;
    }
};