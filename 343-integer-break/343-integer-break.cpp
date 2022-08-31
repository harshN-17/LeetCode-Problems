class Solution {
public:
    // int solve(int sum, int i) {
    //     if(sum == 0 || i == 0) return 1;
    //     if(sum < i) return solve(sum, i - 1);
    //     return max(i * solve(sum - i, i), solve(sum, i - 1));
    // }
    
    int integerBreak(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) dp[i][j] = 1;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j < n; j++) {
                if(i < j) dp[i][j] = dp[i][j - 1];
                else {
                    dp[i][j] = max(j * dp[i - j][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n - 1];
    }
};