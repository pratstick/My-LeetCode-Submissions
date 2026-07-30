class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long N = n * n;

        long long expectedSum = N * (N + 1) / 2;
        long long expectedSqsum = N * (N + 1) * (2 * N + 1) / 6;

        long long sum = 0;
        long long sqSum = 0;

        for (auto &row : grid) {
            for (int num : row) {
                sum += num;
                sqSum += 1LL * num * num;
            }
        }

        long long diff = sum - expectedSum;                 // repeating - missing
        long long summ = (sqSum - expectedSqsum) / diff;    // repeating + missing

        int repeating = (diff + summ) / 2;
        int missing = (summ - diff) / 2;

        return {repeating, missing};
    }
};