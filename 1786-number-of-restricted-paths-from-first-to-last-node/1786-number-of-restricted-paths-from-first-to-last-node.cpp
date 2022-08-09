# define pii pair<int, int>
# define MOD 1000000007
class Solution {
public:
    vector<int> memo;
    int dfs(vector<vector<pii>>& graph, vector<int>& dist, int node) {
        if(node == graph.size() - 1) return 1;
        if(memo[node] != -1) return memo[node];
        int res = 0;
        for(auto child: graph[node]) {
            if(dist[child.first] < dist[node]) {
                res = (res % MOD + dfs(graph, dist, child.first) % MOD) % MOD;
            }
        }
        return memo[node] = res % MOD;
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        memo.assign(n, -1);
        vector<vector<pii>> graph(n);
        for(auto edge: edges) {
            graph[edge[0] - 1].push_back({edge[1] - 1, edge[2]});
            graph[edge[1] - 1].push_back({edge[0] - 1, edge[2]});                
        }
        vector<int> dist(n, INT_MAX);
        dist[n - 1] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, n - 1});
        while(!pq.empty()) {
            int curNode = pq.top().second;
            int curDist = pq.top().first;
            pq.pop();
            for(auto child: graph[curNode]) {
                if(dist[child.first] > curDist + child.second) {
                    dist[child.first] = curDist + child.second;
                    pq.push({dist[child.first], child.first});
                }
            }
        }
        return dfs(graph, dist, 0);
    }
};