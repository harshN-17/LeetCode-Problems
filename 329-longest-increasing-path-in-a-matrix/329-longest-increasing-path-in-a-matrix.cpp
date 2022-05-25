class Solution {
public:
    int dp[200][200];
    int solve(vector<vector<int>>& matrix, int data, int i, int j){
        if(i<0 or i>=matrix.size() or j<0 or j>=matrix[0].size()){
            return 0;
        }
        if(matrix[i][j]<=data){
            return 0;
        }
        if(dp[i][j]) return dp[i][j];
        
        int cur = matrix[i][j];
        int down = 1 + solve(matrix, cur, i+1, j);
        int left = 1 + solve(matrix, cur, i, j-1);
        int right = 1 + solve(matrix, cur, i, j+1);
        int up = 1 + solve(matrix, cur, i-1, j);
        
        return dp[i][j] = max(down,max(left,max(right,up)));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                int t = solve(matrix,-1,i,j);
                ans = max(ans,t);
            }
        }
        return ans;
    }
};