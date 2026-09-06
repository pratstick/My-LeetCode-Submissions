class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return {};
        sort(nums.begin(),nums.end());
        int longest = 1;
        int curr = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1] + 1) {
                curr++;
            }
            else if(nums[i]!=nums[i-1]) curr = 1;
            longest = max(longest,curr);
        }
        return longest;
    }
};