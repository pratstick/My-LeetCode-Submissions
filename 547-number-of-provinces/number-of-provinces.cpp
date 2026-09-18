class Solution {
   private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adjList) {
        vis[node] = 1;
        for (auto& ngh : adjList[node]) {
            if (!vis[ngh]) {
                dfs(ngh, vis, adjList);
            }
        }
    }

   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjList(V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j] == 1) adjList[i].push_back(j);
            }
        }
        vector<int> vis(V, 0);
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, vis, adjList);
            }
        }
        return count;
    }
};
