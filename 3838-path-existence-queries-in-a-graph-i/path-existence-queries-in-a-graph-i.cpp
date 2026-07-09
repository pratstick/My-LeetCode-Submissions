class DisjointSet {
   private:
    vector<int> rank;
    vector<int> parent;

   public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] == rank[pv]) {
            parent[pv] = pu;
            rank[pu]++;
        } else {
            parent[pv] = pu;
        }
    }
};


class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        DisjointSet ds(n);
        for (int i = 0; i < n - 1; i++) {
            if (nums[i+1] - nums[i] <= maxDiff) {
                ds.unionByRank(i, i + 1);
            }
        }
        for(auto&q:queries){
            int u = q[0];
            int v = q[1];
            if(ds.findParent(u)==ds.findParent(v)) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};