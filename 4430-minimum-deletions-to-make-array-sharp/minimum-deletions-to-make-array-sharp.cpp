class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int prev = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==prev) count++;
            prev = nums[i];
        }
        return count;
    }
};