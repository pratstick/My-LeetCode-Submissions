class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *std::min_element(nums.begin(),nums.end());
        int maxi = *std::max_element(nums.begin(),nums.end());
        unordered_set<int>mpp;
        for(int num:nums) mpp.insert(num);
        vector<int> ans;
        for(int i=mini;i<=maxi;i++){
            if(!mpp.count(i)) ans.push_back(i);
        }
        return ans;
    }
};