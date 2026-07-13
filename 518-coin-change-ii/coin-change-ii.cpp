class Solution {
private:
    const int MOD = 1e9+7;
    int helper(int ind, int amount, vector<int>& coins, int n,vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(amount<0||ind>=n) return 0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int not_take = helper(ind+1,amount,coins,n,dp);
        int take = 0;
        if(amount-coins[ind]>=0) take = helper(ind,amount-coins[ind],coins,n,dp);
        return dp[ind][amount] = (take + not_take);
    }
  public:
   int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(0,amount,coins,n,dp);
    }
};
