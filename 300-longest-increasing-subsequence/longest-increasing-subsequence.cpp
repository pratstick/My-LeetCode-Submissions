class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      int len =1;
      vector<int> ans;
      ans.push_back(nums[0]);
      for(int i=1;i<n;i++){
        if(nums[i]>ans.back()) {
            len++;
            ans.push_back(nums[i]);
        }
        else{
            auto it = lower_bound(ans.begin(),ans.end(),nums[i]);
            *it = nums[i];
        }
      }
      return len;
    }    
};