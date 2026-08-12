class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int firstZero = -1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                firstZero = i;
                break;
            }
        }
        if(firstZero==-1) return;
        int left = firstZero;
        for(int i=firstZero;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[left]);
                left++;
            }
        }
        return;
    }
};