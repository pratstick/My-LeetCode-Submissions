class Solution {
public:
    vector<int> getRow(int n) {
        long long curr = 1;
        vector<int>ans;
        ans.push_back(curr);
        for (int k = 1; k <= n; k++) {
            curr = curr * (n - k + 1) / k;
            ans.push_back(curr);
        }
        return ans;
    }
};