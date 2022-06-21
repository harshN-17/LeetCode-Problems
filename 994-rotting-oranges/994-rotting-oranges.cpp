class Solution {
public:
    vector<vector<int>> dir = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    
    int rot(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        
        if(q.empty()) return 0;
        
        int level = 0;
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int x = q.front().first;
                int y = q.front().second;
                grid[x][y] = 0;
                q.pop();
                for(int k = 0; k < 4; k++) {
                    int nx = x + dir[k][0];
                    int ny = y + dir[k][1];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                        q.push({nx,ny});
                        grid[nx][ny] = 0;
                    }
                }
            }
            level++;
        }
        return level - 1;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = rot(grid);        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return res;
    }
};