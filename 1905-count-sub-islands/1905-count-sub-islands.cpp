class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
    void solve(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y, int &flag){
        //base case
        if(x<0 or y<0 or x>=grid1.size() or y>=grid1[0].size()) return;
        
        if(grid1[x][y]==0 and grid2[x][y]==1) flag = 0;
        
        if(!grid2[x][y]) return;
        
        grid2[x][y] = 0;
        
        for(int i=0; i<4; i++){
            int newx = x + dir[i].first;
            int newy = y + dir[i].second;
            solve(grid1, grid2, newx, newy, flag);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j]){
                    int flag = 1;
                    solve(grid1, grid2, i,j, flag);
                    res += flag;
                }
            }
        }
        return res;
    }
};