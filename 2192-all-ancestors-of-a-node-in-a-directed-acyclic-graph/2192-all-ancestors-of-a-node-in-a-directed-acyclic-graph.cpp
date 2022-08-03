class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& vis, vector<vector<int>>& res, int node, int par) {
        vis[node] = true;
        for(auto it: graph[node]) {
            if(!vis[it]) {
                res[it].push_back(par);
                dfs(graph, vis, res, it, par);
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        vector<vector<int>> res(n);
        for(int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            dfs(graph, vis, res, i, i);
        }
        return res;
    }
};