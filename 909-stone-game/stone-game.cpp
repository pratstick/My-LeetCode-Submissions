class Solution {
private:
    int f(int i,int j,int start,vector<int>&piles,int n,vector<vector<vector<int>>>&dp){
        if(i>j||i>=n||j<0) return 0;
        if(dp[i][j][start]!=-1) return dp[i][j][start];
        int begin = INT_MIN;
        int end = INT_MIN;
        if(start==0){
            begin = piles[i] + f(i+1,j,1,piles,n,dp);
            end = piles[j] + f(i,j-1,1,piles,n,dp);
        }        
        else{
            begin = -piles[i] + f(i+1,j,0,piles,n,dp);
            end = -piles[j] + f(i,j-1,0,piles,n,dp);            
        }
        return dp[i][j][start] = max(begin,end);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return f(0,n-1,0,piles,n,dp) > 0;
    }
};