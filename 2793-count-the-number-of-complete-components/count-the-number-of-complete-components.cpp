class DisjointSet {
private:
    vector<int> rank, size;
public:
    vector<int> parent;
    vector<int> edges; // Added to keep track of total edges in each component

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        edges.resize(n + 1, 0); // Initialize edge count to 0
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    
    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    bool find(int u, int v) { return (findParent(u) == findParent(v)); }

    // Modified unionBySize to properly track and merge edge counts
    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        
        if (pu == pv) {
            // Even if they are already connected, this edge still belongs to the component
            edges[pu]++; 
            return;
        }
        
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
            // Transfer edges to the new root and add the current edge (+1)
            edges[pv] += edges[pu] + 1; 
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
            // Transfer edges to the new root and add the current edge (+1)
            edges[pu] += edges[pv] + 1;
        }
    }
    
    int getSize(int node) {
        return size[findParent(node)];
    }
    
    int getEdges(int node) {
        return edges[findParent(node)];
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        
        // 1. DSU insert all edges
        for (const auto& edge : edges) {
            ds.unionBySize(edge[0], edge[1]);
        }
        
        int completeComponentsCount = 0;
        
        // 2. For every component, if V * (V - 1) / 2 == E, it's complete
        for (int i = 0; i < n; i++) {
            // Only check the root of each component to avoid double-counting
            if (ds.parent[i] == i) {
                long long v_count = ds.getSize(i);
                long long e_count = ds.getEdges(i);
                
                long long max_edges = (v_count * (v_count - 1)) / 2;
                
                if (e_count == max_edges) {
                    completeComponentsCount++;
                }
            }
        }
        
        return completeComponentsCount;
    }
};