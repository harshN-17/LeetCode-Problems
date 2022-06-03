class Solution {
public:
    vector<vector<int>> dir = { {0, -1}, {0,1}, {1,0}, {-1,0} } ;
    
    void dfs(vector<vector<int>>& heights, vector<vector<int>>&vis, int i, int j) {
        if(vis[i][j]) return;
        
        int n=heights.size(), m = heights[0].size();
        vis[i][j]=1;
        for(int k=0; k<4; k++){
            int x = dir[k][0] + i;
            int y = dir[k][1] + j;
            if(x >= 0 and y >= 0 and x < n and y < m and !vis[x][y] and  heights[x][y] >= heights[i][j]) {
                dfs(heights, vis, x, y);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(), m = heights[0].size();
        
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        vector<vector<int>> res;

        for(int i=0; i<n; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m-1);
        }
        
        for(int j = 0; j < m ; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, n-1, j);            
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j< m; j++) {
                if(pacific[i][j] and atlantic[i][j]) {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};