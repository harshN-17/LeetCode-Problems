class Solution {
public:
    vector<vector<int>> dir { {0,1}, {0,-1}, {-1,0}, {1,0} };
    int solve(vector<vector<int>>& grid, int i, int j) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return 0;
        int val = grid[i][j];
        grid[i][j] = 0;
        int res = 0;
        for(int k = 0; k < 4; k++) {
            res = max(res, solve(grid, i + dir[k][0], j + dir[k][1]));
        }
        grid[i][j] = val;
        return res + val;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    res = max(res, solve(grid, i, j));
                }
            }
        }
        return res;
    }
};