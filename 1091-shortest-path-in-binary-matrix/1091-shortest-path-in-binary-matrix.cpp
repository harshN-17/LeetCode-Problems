class Solution {
public:
    vector<vector<int>> dir = { {0, -1}, {0, 1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1} } ;
    bool isValid(vector<vector<int>>& grid, vector<vector<int>>& vis, int x, int y, int n){
        return x>=0 and y>=0 and x<n and y<n and !vis[x][y] and grid[x][y]==0 ;
    }
    int solve(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1 and grid[0][0]==0) return 1;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0] = 1;
        queue<pair<int,int>> q;
        q.push({0,0});
        int ans = 1;
        while(!q.empty()) {
            int size = q.size();
            ans++;
            while(size--) {
                auto cur = q.front();
                q.pop();
                for(int i = 0; i <8 ; i++) {
                    int x = cur.first + dir[i][0];
                    int y = cur.second + dir[i][1];
                    if(isValid(grid, vis, x, y, n)) {
                        if(x == n - 1 and y == n - 1) return ans;
                        q.push({x,y});
                        vis[x][y] = 1;
                    }
                }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return -1;
        return solve(grid);
    }
};