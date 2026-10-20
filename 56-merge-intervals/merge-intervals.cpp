class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        int a = intervals[0][0];
        int b = intervals[0][1];

        for (auto&it : intervals) {
            int start = it[0];
            int end = it[1];
            if (start <= b) {
                b = max(b, end);
            } else {
                ans.push_back({a, b});
                a = start;
                b = end;
            }
        }

        ans.push_back({a, b});
        return ans;
    }
};