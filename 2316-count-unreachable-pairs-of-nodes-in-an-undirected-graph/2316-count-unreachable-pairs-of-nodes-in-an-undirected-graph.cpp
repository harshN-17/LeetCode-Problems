class Solution {
public:
    void dfs(vector<vector<int>>& adj, unordered_set<int>& vis, long long& cnt, int node) {
        if(vis.count(node)) return;
        vis.insert(node);
        cnt++;
        for(auto it: adj[node]) {
            dfs(adj, vis, cnt, it);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        int l = edges.size();
        for(int i = 0; i < l; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        long long res = 0;
        unordered_set<int> vis;
        for(int i = 0; i < n; i++) {
            long long cnt = 0;
            if(!vis.count(i)) {
                dfs(adj, vis, cnt, i);
                res += cnt * (n - cnt);
            }
        }
        return res / 2;
    }
};