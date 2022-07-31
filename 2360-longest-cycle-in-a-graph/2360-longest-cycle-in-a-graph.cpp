class Solution {
public:
    int res;
    void dfs(vector<int>& edges, int node, vector<int>& vis, vector<int>& dist, int len) {
        if(!vis[node]) {
            vis[node] = 1;
            dist[node] = len;
            if(edges[node] != -1) dfs(edges, edges[node], vis, dist, len + 1);
            dist[node] = -1;
        }
        
        else {
            if(dist[node] != -1) {
                res = max(res, len - dist[node]);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        res = -1;
        vector<int> vis(n, 0), dist(n, -1);
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0)
                dfs(edges, i, vis, dist, 0);
        }
        return res;
    }
};