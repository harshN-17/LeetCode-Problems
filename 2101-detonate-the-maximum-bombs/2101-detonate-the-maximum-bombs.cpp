class Solution {
public:
    int dfs(vector<vector<int>>& graph, vector<bool> &vis, int node) {
        if(vis[node]) return 0;
        vis[node] = true;
        int res = 1;
        for(auto it: graph[node]) {
            if(!vis[it]) {
                res += dfs(graph, vis, it);
            }
        }
        return res;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        for(int i = 0; i < n; i++) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                long long x2 = bombs[j][0], y2 = bombs[j][1];
                long long dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                if(dist <= r1 * r1) {
                    graph[i].push_back(j);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            res = max(res, dfs(graph, vis, i));
        }
        return res;
    }
};