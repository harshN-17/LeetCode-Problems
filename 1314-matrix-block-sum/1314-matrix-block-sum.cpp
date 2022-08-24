class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1));
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i - 1][j - 1] = prefix[min(n, i + k)][min(m, j + k)] - prefix[max(0, i - k - 1)][min(m,j + k)] - prefix[min(n, i + k)][max(0, j - k - 1)] + prefix[max(0, i - k - 1)][max(0, j - k - 1)];
            }
        }
        return dp;
    }
};