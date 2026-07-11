class Solution {
private:
    const int MOD = 1e9 + 7;
    int total = 0;
    int helper(int ind, int sum, vector<int>& nums,int n, int target,vector<vector<int>>&dp){
        if (sum < 0 || sum > 2 * total) return 0;
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
        total = accumulate(nums.begin(), nums.end(), 0); //offset
        vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));
        return helper(0,total,nums,n,target+total,dp);
 }
};
