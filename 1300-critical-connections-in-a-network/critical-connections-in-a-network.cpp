class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj,
             vector<int>& tin, vector<int>& low, vector<vector<int>>& bridges) {
        vis[node] = 1;
        tin[node] = timer;
        low[node] = timer;
        timer++;
        for (auto& it : adj[node]) {
            if (it == parent)
                continue;
            if (!vis[it]) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }

            } else
                low[node] = min(low[node], tin[it]);
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> bridges;

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(i, -1, vis, adj, tin, low, bridges);
        }
        return bridges;
    }
};