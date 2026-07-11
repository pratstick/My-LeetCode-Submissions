class Solution {
private:
    const int MOD = 1e9 + 7;
    int helper(int ind, int sum, vector<int>& nums,int n, int target,vector<vector<int>>&dp){
        if(ind==n){
            if(sum==target) return 1;
            else return 0;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int neg = helper(ind+1,sum+nums[ind],nums,n,target,dp); 
        int pos = helper(ind+1,sum-nums[ind],nums,n,target,dp);
        return dp[ind][sum] = (neg + pos) % MOD;
    }
public:
  int findTargetSumWays(vector<int>& nums,int target) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(6000,-1));
        return helper(0,3000,nums,n,target+3000,dp);
 }
};
