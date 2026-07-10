class Answer {
    bool helper(int ind, int target, const vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (ind >= arr.size() || target < 0) return false;
        
        if (dp[ind][target] != -1) return dp[ind][target];
        
        bool include = false;
        if (arr[ind] <= target) {
            include = helper(ind + 1, target - arr[ind], arr, dp);
        }
        
        bool exclude = helper(ind + 1, target, arr, dp);
        
        return dp[ind][target] = (include || exclude);
    }

public:
    bool isSubsetSum(const vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return helper(0, target, arr, dp);
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto& num : nums)
            sum += num;
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        Answer obj;
        return obj.isSubsetSum(nums, target);
    }
};