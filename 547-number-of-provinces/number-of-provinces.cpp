class DisjointSet {
private:
    vector<int> rank;
    vector<int> parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    bool find(int u, int v) { return (findParent(u) == findParent(v)); }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return;
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
    int findCircleNum(vector<vector<int>>& adj) {
        unordered_set<int> set;
        int n = adj.size();
        DisjointSet ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] == 1) {
                    if (i < j)
                        ds.unionByRank(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int p = ds.findParent(i);
            set.insert(p);
        }

        return set.size();
    }
};
