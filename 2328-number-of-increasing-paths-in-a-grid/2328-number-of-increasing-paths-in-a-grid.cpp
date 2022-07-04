class Solution {
public:
    long long md = 1000000007;
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& grid, int i, int j){
        if(dp[i][j] != -1) return dp[i][j];
        int res = 1;
        for(int k = 0; k < 4; k++) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] > grid[i][j])
                res = (res + solve(grid, x, y)) % md;
        }
        return dp[i][j] = res;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        dp.resize(r, vector<int>(c,-1));
        int res = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                res = (res + solve(grid, i, j)) % md;
            }
        }
        return res % md;    
    }
};