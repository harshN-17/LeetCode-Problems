class Solution {
public:
    int dfs(vector<vector<int>>& graph, vector<bool>& vis, int node) {
        if(vis[node]) return 0; 
        vis[node] = true;
        int res = 1;
        for(auto child: graph[node]) {
            if(!vis[child]) {
                res += dfs(graph, vis, child);
            }
        }
        return res;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> graph(n);
        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);            
        }
        vector<bool> vis(n, false);
        for(auto it: restricted) {
            vis[it] = true;
        }
        return dfs(graph, vis, 0);
    }
};