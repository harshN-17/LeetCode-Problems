class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<bool>> &vis, int i, int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0)
            return 0;
        if(vis[i][j]) return 0;
        vis[i][j] = true;
        int left = solve(grid, vis, i,j-1);
        int right = solve(grid, vis, i,j+1);
        int up = solve(grid, vis, i-1,j);
        int down = solve(grid, vis, i+1,j);
        // cout<<left<<' '<<right<<' '<<up<<' '<<down<<endl;
        return 1 + left + right + up + down;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(),false));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(!vis[i][j] and grid[i][j]){
                    ans = max(ans,solve(grid, vis, i, j));
                }
            }
        }
        return ans;
    }
};