#define pii pair<int, int>
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pii>> graph(n);
        for(auto &edge: edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        while(!pq.empty()) {
            auto [curDist, curNode] = pq.top();
            pq.pop();
            if(dist[curNode] < curDist) continue;
            for(auto child: graph[curNode]) {
                if(dist[child.first] > curDist + child.second + 1) {
                    dist[child.first] = curDist + child.second + 1;
                    pq.push({dist[child.first], child.first});
                }
            }
        }
        int res = 0;
        for(auto &x: dist) {
            if(x <= maxMoves) res++;
        }
        for(auto &edge: edges) {
            int x = max(0, maxMoves - dist[edge[0]]);
            int y = max(0, maxMoves - dist[edge[1]]);
            res += min(edge[2], x + y);
        }
        return res;
    }
};