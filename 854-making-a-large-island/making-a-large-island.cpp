class DisjointSet {
   public:
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
private:
    int n;
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};
    bool isValid(int i,int j){
        if(i<0||j<0||i>=n||j>=n) return false;
        return true;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        DisjointSet ds(n*n);
        //componenets connected
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==0) continue;
                for(int k = 0;k<4;k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if(isValid(nr,nc) && grid[nr][nc]==1){
                        int node = n*i+j;
                        int adjNode = nr*n+nc;
                        ds.unionBySize(node,adjNode);
                    }
                }
            }
        }

        // step2
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)continue;
                set<int>componenets; //unique parents
                for(int k = 0;k<4;k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if(isValid(nr,nc) && grid[nr][nc]==1){
                        int node = n*i+j;
                        int adjNode = nr*n+nc;
                        componenets.insert(ds.findParent(adjNode));
                    }
                }
                int sizeTotal = 1;
                for(auto&it:componenets){
                    sizeTotal+=ds.size[it];
                }
                maxi = max(maxi,sizeTotal);
            }
        }
        for(int cell = 0; cell < n*n; cell ++){
            maxi = max(maxi, ds.size[ds.findParent(cell)]);
        }
        return maxi;

    }
};
