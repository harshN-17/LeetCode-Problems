class Solution {
public:
    void bfs(vector<int>& edges, vector<int>& dist, int node) {
        queue<int> q;
        q.push(node);
        dist[node] = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            if(edges[cur] != -1 && dist[edges[cur]] == INT_MAX) {
                q.push(edges[cur]);
                dist[edges[cur]] = dist[cur] + 1;
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int n1, int n2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        bfs(edges, dist1, n1);
        bfs(edges, dist2, n2);
        int res = INT_MAX, node = -1;      
        for(int i = 0; i < n; i++) {
            if(dist1[i] != INT_MAX || dist2[i] != INT_MAX) {
                if(res > max(dist1[i], dist2[i])) {
                    node = i;
                    res = max(dist1[i], dist2[i]);
                }
            }
        }
        return node;
    }
};