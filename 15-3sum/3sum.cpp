class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if(nums[i]  > 0 ) break;
            int low = i+1;
            int high = n - 1;
            while (low < high) {
                int target = nums[i] + nums[low] + nums[high];
                if (target > 0) {
                    high--;
                } else if (target < 0)
                    low++;
                else{
                    ans.push_back({nums[i], nums[low], nums[high]});
                    while (low < high && nums[low] == nums[low + 1])
                        low++;
                    while(low < high && nums[high] == nums[high - 1]){
                        high--;
                    }
                    low++;
                    high--;
                }
            }
        }
        return ans;
    }
};