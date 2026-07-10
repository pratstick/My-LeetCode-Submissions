class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for (int num : nums) total_sum += num;
        
        int target = total_sum / 2;
        int half = n / 2;
        
        // left_sums[k] stores all possible sums using exactly 'k' elements from the left half
        vector<vector<int>> left_sums(half + 1);
        vector<vector<int>> right_sums(half + 1);
        
        // Generate subset sums for left half
        for (int i = 0; i < (1 << half); ++i) {
            int sum = 0, count = 0;
            for (int j = 0; j < half; ++j) {
                if (i & (1 << j)) {
                    sum += nums[j];
                    count++;
                }
            }
            left_sums[count].push_back(sum);
        }
        
        // Generate subset sums for right half
        for (int i = 0; i < (1 << half); ++i) {
            int sum = 0, count = 0;
            for (int j = 0; j < half; ++j) {
                if (i & (1 << j)) {
                    sum += nums[half + j];
                    count++;
                }
            }
            right_sums[count].push_back(sum);
        }
        
        // Sort right sums to enable binary search
        for (int i = 0; i <= half; ++i) {
            sort(right_sums[i].begin(), right_sums[i].end());
        }
        
        int min_diff = INT_MAX;
        
        // For each size k chosen from left, we need (half - k) elements from right
        for (int k = 0; k <= half; ++k) {
            for (int l_sum : left_sums[k]) {
                int r_target = target - l_sum;
                auto& r_list = right_sums[half - k];
                
                // Binary search for the closest sum in the right half
                auto it = lower_bound(r_list.begin(), r_list.end(), r_target);
                
                if (it != r_list.end()) {
                    int current_sum = l_sum + *it;
                    min_diff = min(min_diff, abs(total_sum - 2 * current_sum));
                }
                if (it != r_list.begin()) {
                    int current_sum = l_sum + *prev(it);
                    min_diff = min(min_diff, abs(total_sum - 2 * current_sum));
                }
            }
        }
        
        return min_diff;
    }
};