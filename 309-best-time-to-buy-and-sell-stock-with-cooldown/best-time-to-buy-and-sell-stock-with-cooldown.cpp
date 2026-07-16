class Solution{
private:
    int helper(int ind,int buy, vector<int>& arr, int n,vector<vector<int>>&dp){
        if(ind>=n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            return dp[ind][1] = max(-arr[ind]+helper(ind+1,0,arr,n,dp),helper(ind+1,1,arr,n,dp));
        }
        else{
             return dp[ind][0] = max(arr[ind]+helper(ind+2,1,arr,n,dp),helper(ind+1,0,arr,n,dp));
        }
    }
public:
    int maxProfit(vector<int>& arr){
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,1,arr,n,dp);
    }
};