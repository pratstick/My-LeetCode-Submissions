class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }        
        for(auto&it:mpp){
            int num = it.first;
            int freq = it.second;
            if(freq > n/3) ans.push_back(num);
        }
        return ans;
    }
};