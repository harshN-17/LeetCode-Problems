class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i][j] = triangle[i - 1][j - 1] + min(dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
        return *min_element(dp[n].begin(), dp[n].end());
    }
};