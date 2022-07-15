class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0)
            return 0;
        grid[i][j] = 0;
        int left = solve(grid, i,j-1);
        int right = solve(grid, i,j+1);
        int up = solve(grid, i-1,j);
        int down = solve(grid, i+1,j);
        // grid[i][j] = 1;
        // cout<<left<<' '<<right<<' '<<up<<' '<<down<<endl;
        return 1 + left + right + up + down;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]){
                    ans = max(ans,solve(grid, i, j));
                }
            }
        }
        return ans;
    }
};