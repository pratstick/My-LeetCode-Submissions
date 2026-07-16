class Solution{
private:
    int helper(int ind,int buy, vector<int>& arr, int n, int fee,vector<vector<int>>&dp){
        if(ind>=n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            return dp[ind][1] = max(-arr[ind]+helper(ind+1,0,arr,n,fee,dp),helper(ind+1,1,arr,n,fee,dp));
        }
        else return dp[ind][0] = max(-fee+arr[ind]+helper(ind+1,1,arr,n,fee,dp),helper(ind+1,0,arr,n,fee,dp));
    }
public:
    int maxProfit(vector<int>& arr, int fee){
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,1,arr,n,fee,dp);
    }
};
