class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        int maxi = nums[0];
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            left[i] = maxi;
        }
        int mini = nums[n-1];
        for(int i=n-1;i>=0;i--){
            mini = min(mini, nums[i]);
            right[i] = mini;
        }

        for(int i=0;i<n;i++){
            if((left[i] - right[i]) <= k) return i;
        }
        return -1;

    }
};