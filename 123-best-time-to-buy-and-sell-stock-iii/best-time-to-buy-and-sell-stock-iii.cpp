class Solution {
private:
    int f(int ind, int buy, int txn, vector<int>&arr, int n,vector<vector<vector<int>>>&dp){
        if(ind>=n||txn>=2) return 0;
        if(dp[ind][buy][txn]!=-1) return dp[ind][buy][txn];
        if(buy){
            return dp[ind][buy][txn] = max(-arr[ind] + f(ind+1,0,txn,arr,n,dp),f(ind+1,1,txn,arr,n,dp));
        }
        else return dp[ind][buy][txn] = max(arr[ind] + f(ind+1,1,txn+1,arr,n,dp),f(ind+1,0,txn,arr,n,dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));        
        return f(0,1,0,prices,n,dp);
    }
};