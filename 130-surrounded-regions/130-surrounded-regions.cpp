class Solution {
public:
    vector<vector<int>> dir = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') q.push({i,0});
            if(board[i][m-1] == 'O') q.push({i,m-1});
        }
        for(int i = 0; i < m; i++) {
            if(board[0][i] == 'O') q.push({0,i});
            if(board[n-1][i] == 'O') q.push({n-1,i});
        }
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                vis[x][y] = true;
                for(int i = 0; i < 4; i++) {
                    int nx = x + dir[i][0];
                    int ny = y + dir[i][1];
                    if(nx>=0 and ny>=0 and nx<n and ny<m and board[nx][ny] == 'O' and !vis[nx][ny]) {
                        q.push({nx,ny});
                        vis[nx][ny] = true;
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] and board[i][j] == 'O') {
                    vis[i][j] = true;
                    board[i][j] = 'X';
                }
            }
        }
    }
};