# define ll long long
# define pll pair<ll, ll>
# define MOD 1000000007
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph(n);
        for(auto road: roads) {
                graph[road[0]].push_back({road[1], road[2]});
                graph[road[1]].push_back({road[0], road[2]});
        }
        vector<ll> dist(n, LLONG_MAX);
        vector<ll> dp(n, 0);
        dp[0] = 1;
        dist[0] = 0;
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            ll curDist = pq.top().first;
            ll curNode = pq.top().second;
            pq.pop();
            for(auto it: graph[curNode]) {
                if(dist[it.first] == curDist + it.second) {
                    dp[it.first] = (dp[curNode] + dp[it.first]) % MOD;
                }
                if(dist[it.first] > curDist + it.second) {
                    dist[it.first] = curDist + it.second;
                    dp[it.first] = dp[curNode] % MOD;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        return dp[n - 1];
    }
};