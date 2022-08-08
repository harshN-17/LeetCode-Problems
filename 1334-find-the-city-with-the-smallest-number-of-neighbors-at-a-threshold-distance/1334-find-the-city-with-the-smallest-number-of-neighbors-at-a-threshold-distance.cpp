# define pii pair<int, int>
class Solution {
public:
    int solve(int n, vector<vector<pii>> graph, int threshold, int node) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n, INT_MAX);
        int cnt = 0;
        pq.push({0, node});
        dist[node] = 0;
        while(!pq.empty()) {
            int curDist = pq.top().first;
            int curNode = pq.top().second;
            pq.pop();
            for(auto child: graph[curNode]) {
                if(dist[child.first] > curDist + child.second) {
                    dist[child.first] = curDist + child.second;
                    pq.push({dist[child.first], child.first});
                }
            }
        }
        for(auto x: dist) {
            if(x <= threshold) cnt++;
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pii>> graph(n);
        for(auto edge: edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        int cnt = INT_MAX, res = -1;
        for(int i = 0; i < n; i++) {
            int temp = solve(n, graph, distanceThreshold, i);
            if(cnt >= temp) {
                cnt = temp;
                res = i;
            }
        }
        return res;
    }
};