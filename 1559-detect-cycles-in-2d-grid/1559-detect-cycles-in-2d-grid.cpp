class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool isCyclic(vector<vector<char>>& grid, int px, int py, int x, int y, char ch, vector<vector<int>> &vis) {
        if(vis[x][y] == 1) return true;
        vis[x][y] = 1;
        for(int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx == px && ny == py) continue;
            if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) continue;
            if(grid[nx][ny] == ch) {
                if(isCyclic(grid, x, y, nx, ny, ch, vis)) return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {
                    if(isCyclic(grid, -1, -1, i, j, grid[i][j], vis)) return true;
                }
            }
        }
        return false;
    }
};