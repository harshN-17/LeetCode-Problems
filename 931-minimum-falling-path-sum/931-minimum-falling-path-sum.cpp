class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int res = INT_MAX;
        vector<vector<int>> dp(matrix.begin(), matrix.end());
        for(int i = 1; i < n; i++) {
             for(int j = 0; j < n; j++) {
                 int left = matrix[i - 1][max(0, j - 1)];
                 int mid = matrix[i - 1][j];
                 int right = matrix[i - 1][min(j + 1, n - 1)];
                 matrix[i][j] += min({left, mid, right});
             }
        }
        
        for(int i = 0; i < n; i++) {
            res = min(res, matrix[n - 1][i]);
        }
        return res;
    }
};