class Solution {
    int helper(int i, int j, const vector<int>& nums1, const vector<int>& nums2, int& highest,vector<vector<int>>& dp){
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        helper(i - 1, j, nums1, nums2, highest, dp);
        helper(i, j - 1, nums1, nums2, highest, dp);
        if(nums1[i]==nums2[j]){
            dp[i][j] = 1 + helper(i-1,j-1,nums1,nums2,highest,dp);
        }
        else{
            dp[i][j] = 0;
        }
        highest = max(highest,dp[i][j]);
        return dp[i][j];
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int highest = 0;
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        helper(m-1,n-1,nums1,nums2,highest,dp);
        return highest;
    }
};