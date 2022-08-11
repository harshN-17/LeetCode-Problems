class Solution {
public:
    bool bfs(vector<vector<int>>& graph, int start, vector<int>& arr) {
        vector<int> vis(graph.size());
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            if(arr[cur] == 0) return true;
            for(auto it: graph[cur]) {
                if(!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size(), dest = -1;
        vector<vector<int>> graph(n);
        for(int i = 0; i < n; i++) {
            if(arr[i] + i < n) graph[i].push_back(arr[i] + i);
            if(i - arr[i] >= 0) graph[i].push_back(i - arr[i]);
        }
        return bfs(graph, start, arr);
    }
};




