class Solution {
private:
    const int MOD = 1e9 + 7;
    int helper(int ind, int sum, vector<int>& nums,int n, int target){
        if(ind==n){
            if(sum==target) return 1;
            else return 0;
        }
        int neg = helper(ind+1,sum+nums[ind],nums,n,target); 
        int pos = helper(ind+1,sum-nums[ind],nums,n,target);
        return (neg + pos) % MOD;
    }
public:
  int findTargetSumWays(vector<int>& nums,int target) {
        int n = nums.size();
        return helper(0,0,nums,n,target);
 }
};
