class DisjointSet {
private:
    vector<int> rank, size;
    vector<int> parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
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

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return;
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mpp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mpp.find(mail) == mpp.end())
                    mpp[mail] = i;
                else
                    ds.unionByRank(i, mpp[mail]);
            }
        }

        vector<vector<string>> list(n);
        for (auto& it : mpp) {
            string mail = it.first;
            int accId = it.second;
            int rootParent = ds.findParent(accId);
            list[rootParent].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (list[i].size() == 0)
                continue;
            sort(list[i].begin(), list[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto& it : list[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};