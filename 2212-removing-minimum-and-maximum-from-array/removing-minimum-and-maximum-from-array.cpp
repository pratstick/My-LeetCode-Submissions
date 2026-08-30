class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi = INT_MIN, mini = INT_MAX;
        int max_ind = -1, min_ind = -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                max_ind = i;
            }
            if(nums[i] < mini){
                mini = nums[i];
                min_ind = i;
            }
        }
        int left = min(min_ind,max_ind);
        int right = max(min_ind, max_ind);
        return min({right + 1, n - left, left + 1 + n - right});
    }
};