class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) q.push({i,j});
            }
        }
        vector<int> vis(m + n, 0);
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if(vis[x] == 0) {
                vis[x] = 1;
                for(int i = 0; i < n; i++) {
                    matrix[x][i] = 0;
                }
            }
            if(vis[m + y] == 0) {
                vis[m + y] = 1;
                for(int i = 0; i < m; i++) {
                    matrix[i][y] = 0;
                }
            }
        }
    }
};