class Answer {
public:
    bool isSubsetSum(const vector<int>& arr, int target) {
        int n = arr.size();        
        vector<int>prev(target+1,0);
        prev[0] = true;
        if(arr[0] <= target) prev[arr[0]] = true;
        for(int i = 1; i<n; i++){
            vector<int>curr(target+1,0);
            curr[0] = true;
            for(int j=1;j<=target;j++){
                bool exclude = prev[j];
                bool include = false;
                if(arr[i]<=j) include = prev[j-arr[i]];
                curr[j] = include || exclude;
            }
            prev = curr;
        }
        return prev[target];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto& num : nums)
            sum += num;
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        Answer obj;
        return obj.isSubsetSum(nums, target);
    }
};