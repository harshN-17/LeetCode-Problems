class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, INT_MAX));
        for(int i = 1; i <=n; i++) dp[0][i] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]}) + matrix[i - 1][j - 1];
            }
        }
        return *min_element(dp[n].begin(), dp[n].end());
    }
};