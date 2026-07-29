class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int countZero = 0;
        int start = 0;
        int end = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) countZero++;
            end++;
            while(countZero>1){
                if(nums[start]==0)countZero--;
                start++;
            }
            
            ans = max(ans, end - start);
        }
        return ans-1;
    }
};