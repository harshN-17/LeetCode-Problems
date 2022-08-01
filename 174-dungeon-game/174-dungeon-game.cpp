class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));        
        dp[n][m - 1] = dp[n - 1][m] = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                int res = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = res <= 0 ? 1 : res;
            }
        }
        return dp[0][0];
    }
};


// int solve(vector<vector<int>>& dungeon, int i, int j) {
//     if(i >= dungeon.size() || j >= dungeon[0].size()) return INT_MAX;
//     if(i == dungeon.size() - 1 && j == dungeon[0].size() - 1) {
//         if(dungeon[i][j] < 0) return -dungeon[i][j] + 1;
//         return 1;
//     }
//     int down = solve(dungeon, i + 1, j);
//     int right = solve(dungeon, i, j + 1);

//     int res = min(down, right) - dungeon[i][j];
//     return res <= 0 ? 1 : res;
// }
// int calculateMinimumHP(vector<vector<int>>& dungeon) {
//     return solve(dungeon, 0, 0);
// }