class Solution {
public:
    # define MOD 1000000007
    unordered_map<string, int> dp;
    vector<vector<int>> dir = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
    int findPaths(int m, int n, int maxMove, int x, int y) {
        if(x < 0 || y < 0 || x >= m || y >= n) return 1;
        if(maxMove <= 0) return 0;
        string s = to_string(maxMove) + "-" + to_string(x) + "-" + to_string(y);
        if(dp.find(s) != dp.end()) return dp[s];
        int res = 0;
        for(int i = 0; i < 4; i++) {
            res = (res + findPaths(m, n, maxMove - 1, x + dir[i][0], y + dir[i][1])) % MOD;
        }
        return dp[s] = res % MOD;
    }
};