class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0];
        int sum = 0;
        for (int num : nums) {
            if (num == ele)
                sum++;
            else {
                sum--;
                if (sum < 0) {
                    ele = num;
                    sum = 1;
                }
            }
        }
        return ele;
    }
};