class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(triangle.begin(), triangle.end());
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                dp[i][j] = min(dp[i - 1][min(i - 1, j)], dp[i - 1][max(0, j - 1)]) + triangle[i][j];
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};