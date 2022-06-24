class Solution {
public:
    unordered_map<string, double> dp;
    vector<vector<int>> dir = {{-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}};
    double solve(int n, int k, int i, int j) {
        if(i<0 || j<0 || i>=n || j>=n) return 0;
        if(k == 0) return  1;
        string key = to_string(k) + '-' + to_string(i) + '-' + to_string(j);
        if(dp.find(key) != dp.end()) return dp[key];
        double res = 0;
        for(int it = 0; it < 8; it++) {
            res += (0.125 * solve(n, k - 1, i + dir[it][0], j + dir[it][1]));
        }
        return dp[key] = res;
    }
    double knightProbability(int n, int k, int row, int column) {
        return solve(n, k, row, column);
    }
};