class Solution {
public:
    vector<vector<int>> dir = { {0,1}, {0,-1}, {-1,0}, {1,0} };
    int empty = 1, res=0;
    void solve(vector<vector<int>>& grid, int sr, int sc) {
        if(sr<0 || sc<0 || sr>=grid.size() || sc>=grid[0].size() || grid[sr][sc] <0) return;
        if(grid[sr][sc] == 2){
            if(empty == 0) res++;
            return;
        } 
        
        grid[sr][sc] = -1;
        empty--;
        for(int i = 0; i < 4; i++) {
            solve(grid, sr + dir[i][0], sc + dir[i][1]);
        }
        grid[sr][sc] = 0;
        empty++;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sr, sc;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    sr = i; sc = j;
                }
                else if(grid[i][j] == 0) empty++;
            }
        }
        solve(grid, sr, sc);
        return res;
    }
};