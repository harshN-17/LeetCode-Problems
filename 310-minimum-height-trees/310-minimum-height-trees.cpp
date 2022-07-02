class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degree(n);
        int m = edges.size();
        for(int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(degree[i] == 1) q.push(i);
        }
        vector<int> res;
        while(!q.empty()) {
            int size = q.size();
            res.clear();
            while(size--) {
                int cur = q.front();
                q.pop();
                res.push_back(cur);
                for(auto it: adj[cur]) {
                    if(--degree[it] == 1) q.push(it);
                }
            }
        }
        return res;
    }
};