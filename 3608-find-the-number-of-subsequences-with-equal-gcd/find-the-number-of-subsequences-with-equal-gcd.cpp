class Solution {
private:
    const int MOD = 1e9+7;
    int helper(int ind, int g1, int g2, vector<int>& nums,vector<vector<vector<int>>>&dp){
        if(ind<0){
            return (g1!=0 && g1==g2);
        }
        if(dp[ind][g1][g2]!=-1) return dp[ind][g1][g2];
        int notTake = helper(ind-1,g1,g2,nums,dp) % MOD;
        int newg1 = (g1==0)?nums[ind]:gcd(g1,nums[ind]) ;
        int take1 = helper(ind-1,newg1,g2,nums,dp)% MOD;
        int newg2 = (g2==0)?nums[ind]:gcd(g2,nums[ind]);
        int take2 = helper(ind-1,g1,newg2,nums,dp)% MOD;

        return dp[ind][g1][g2] = (1LL * notTake + take1 + take2)% MOD;        
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>>dp(n,(vector<vector<int>>(201,vector<int>(201,-1))));
        return helper(n-1,0,0,nums,dp);
    }
};