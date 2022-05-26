class Solution {
public:    
    int solve(vector<vector<int>>& grid, int r, int c, int i, int j){
        if(i<0 or j<0 or i>=r or j>=c) return -1;
        if(!grid[i][j]) return 0;
        
        grid[i][j]=0;
        
        int left = solve(grid, r,c, i,j-1);
        int right = solve(grid, r,c, i,j+1);
        int up = solve(grid, r,c, i-1,j);
        int down = solve(grid, r,c, i+1,j);
        
        if(left==-1 or right==-1 or up==-1 or down==-1) return -1;
        
        return 1 + left + right + up + down;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size(), cnt=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]){
                    int t = solve(grid,r,c,i,j);
                    cnt += (t == -1 ? 0 : t);
                }
            }
        }
        return cnt;
    }
};