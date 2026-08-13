class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        unordered_set<int>st1,st2;
        vector<int>ans;
        for(int num:nums1) st1.insert(num);
        for(int num:nums2) st2.insert(num);
        for(int num:st1){
            if(st2.count(num)) ans.push_back(num);
        }
        return ans;
    }
};