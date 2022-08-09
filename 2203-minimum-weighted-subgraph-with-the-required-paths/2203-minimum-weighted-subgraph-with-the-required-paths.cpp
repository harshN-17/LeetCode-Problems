# define pll pair<long, long>
class Solution {
public:
    vector<long> dijkstra(vector<vector<pll>>& graph, int src) {
        int n = graph.size();
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        vector<long> dist(n, LONG_MAX);
        pq.push({0, src});
        dist[src] = 0;
        while(!pq.empty()) {
            long curDist = pq.top().first;
            int curNode = pq.top().second;
            pq.pop();
            if(curDist > dist[curNode]) continue;
            for(auto child: graph[curNode]) {
                if(dist[child.first] > curDist + child.second) {
                    dist[child.first] = curDist + child.second;
                    pq.push({dist[child.first], child.first});
                }
            }
        }
        return dist;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pll>> graph(n), rev(n);    
        for(auto edge: edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            rev[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<long> dist1 = dijkstra(graph, src1);
        vector<long> dist2 = dijkstra(graph, src2);
        vector<long> dist3 = dijkstra(rev, dest);
        long res = LONG_MAX;
        for(int i = 0; i < n; i++) {
            if(dist1[i] == LONG_MAX || dist2[i] == LONG_MAX || dist3[i] == LONG_MAX) continue;
            res = min(res, dist1[i] + dist2[i] + dist3[i]);
        }
        return res == LONG_MAX ? -1 : res;
    }
};