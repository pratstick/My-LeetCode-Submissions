class DisjointSet {
   private:
    vector<int> rank, size;
    vector<int> parent;

   public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    bool find(int u, int v) { return (findParent(u) == findParent(v)); }

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

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
      int maxRow = 0;
      int maxCol = 0;
      for(auto&it:stones){
        maxRow = max(maxRow,it[0]);
        maxCol = max(maxCol,it[1]);
      }
      DisjointSet ds(maxRow + maxCol + 1);
      unordered_set<int> set;
      for(auto&it:stones){
        int nodeRow = it[0];
        int nodeCol = maxRow + 1 + it[1];
        ds.unionByRank(nodeRow, nodeCol);
        set.insert(nodeRow);
        set.insert(nodeCol);
      }
      int count = 0;
      for(auto&it:set){
        if(ds.findParent(it)==it) count++;
      }
      return stones.size() - count;
    }
};