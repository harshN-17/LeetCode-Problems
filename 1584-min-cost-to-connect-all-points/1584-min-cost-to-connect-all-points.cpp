# define pii pair<int, int>
class Solution {
public:
    int prims(vector<vector<pii>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,0});
        int res = 0;
        while(!pq.empty()) {
            auto [curDist, curNode] = pq.top();
            pq.pop();
            if(vis[curNode]) continue;
            res += curDist;
            vis[curNode] = true;
            for(auto &child: graph[curNode]) {
                if(!vis[child.first]) {
                    pq.push({child.second, child.first});
                }
            }
        }
        return res;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pii>> graph(n);
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph[i].push_back({j,dist});
                graph[j].push_back({i,dist});
            }
        }
        return prims(graph);
    }
};