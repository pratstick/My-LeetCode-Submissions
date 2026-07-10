class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int p1 = 0;
        int p2 = 0;
        for(int i=2;i<=n;i++){
            int curr = min(cost[i-2] + p2, cost[i-1]+ p1);
            p2 = p1;
            p1 = curr;
        }
        return p1;
    }
};