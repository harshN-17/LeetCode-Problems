# define pii pair<int, int>
class Solution {
public:
    vector<vector<int>> dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            int curdist = pq.top().first;
            int x = pq.top().second / 100;
            int y = pq.top().second % 100;
            pq.pop();
            if(x == n - 1 && y == m - 1) return curdist;
            for(int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                int newdist = max(curdist, abs(heights[x][y] - heights[nx][ny]));
                if(dist[nx][ny] > newdist) {
                    dist[nx][ny] = newdist;
                    pq.push({dist[nx][ny], nx*100 + ny});
                }
            }
        }
        return -1;
    }
};