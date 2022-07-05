class Solution {
public:
    vector<vector<int>> dp;
    int solve(int cur, int n, int last) {
        if(cur == n) return 0;
        if(cur > n) return 1000000;
        if(dp[cur][last] != -1) return dp[cur][last];
        
        int copy = 2 + solve(2 * cur, n, cur);
        int paste = 1 + solve(cur + last, n, last);
        
        return dp[cur][last] = min(copy, paste);
    }
    int minSteps(int n) {
        if(n <= 1) return 0;
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return 1 + solve(1, n, 1);
    }
};