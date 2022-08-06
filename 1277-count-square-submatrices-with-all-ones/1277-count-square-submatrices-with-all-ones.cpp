class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++){
                if(matrix[i - 1][j - 1]) {
                    dp[i][j] = matrix[i - 1][j - 1] + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                }
            }
        }
        int sum = 0;
        for(auto row: dp) {
            for(auto cell: row) {
                sum += cell;
            }
        }
        return sum;
    }
};