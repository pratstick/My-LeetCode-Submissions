class Answer {
    bool helper(int ind, int sum, int target, vector<int>& arr,
                vector<vector<int>>& dp) {
        if (sum > target)
            return false;
        if (sum == target)
            return true;
        if (ind >= arr.size())
            return false;
        if (dp[ind][sum] != -1)
            return dp[ind][sum];
        if (helper(ind + 1, sum + arr[ind], target, arr, dp))
            return dp[ind][sum] = true;
        if (helper(ind + 1, sum, target, arr, dp))
            return dp[ind][sum] = true;
        return dp[ind][sum] = false;
    }

public:
    bool isSubsetSum(vector<int>& arr, int target) {
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));

        return helper(0, 0, target, arr, dp);
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