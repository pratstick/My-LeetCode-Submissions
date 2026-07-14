class Solution {
    private:
    int helper(int i, int j,string s1, string s2, vector<vector<int>>&dp){
        if(j<0) return i+1;
        if(i<0) return j+1;
        if(dp[i][j]!=-1) return dp[i][j];
        int match = 1e9;
        if(s1[i]==s2[j]) match = helper(i-1,j-1,s1,s2,dp);
        int insert = 1 + helper(i,j-1,s1,s2,dp);
        int del = 1 + helper(i-1,j,s1,s2,dp);
        int replace = 1 + helper(i-1,j-1,s1,s2,dp);
        return dp[i][j] = min({insert,del,replace,match});
    }
  public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,word1,word2,dp);
    }
};

