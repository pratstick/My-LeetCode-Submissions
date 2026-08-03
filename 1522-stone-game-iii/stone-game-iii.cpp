class Solution {
private:
    int f(int ind, vector<int>& stoneValue, int n, vector<int>& dp) {
        if (ind >= n) return 0;
        if (dp[ind] != INT_MIN) return dp[ind];
        int maxDiff = INT_MIN;
        int currentSum = 0;
        // Try taking 1, 2, or 3 stones
        for (int k = 1; k <= 3 && ind + k <= n; ++k) {
            currentSum += stoneValue[ind + k - 1];
            // Score gained by current player minus optimal score opponent gets from ind + k
            maxDiff = max(maxDiff, currentSum - f(ind + k, stoneValue, n, dp));
        }

        return dp[ind] = maxDiff;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);
        
        int ans = f(0, stoneValue, n, dp);

        if (ans > 0) return "Alice";
        if (ans < 0) return "Bob";
        return "Tie";
    }
};