class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for(auto it: times) {
            graph[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        queue<int> q;
        q.push(k);
        dist[k] = 0;
        while(!q.empty()) {
            int t = 0;  
            int cur = q.front();
            q.pop();
            for(auto it: graph[cur]) {
                if(dist[it.first] > dist[cur] + it.second) {
                    dist[it.first] = dist[cur] + it.second;
                    q.push(it.first);
                }
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};