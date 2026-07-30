class Solution {
public:
    bool search(vector<int> &nums, int k)  {
      auto it = find(nums.begin(),nums.end(),k);
      return it!=nums.end();
    }
};