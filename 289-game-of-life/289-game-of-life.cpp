class Solution {
public:
    vector<vector<int>> dir = { {0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {-1,-1}, {-1,1}, {1,-1} };
    int countLive(vector<vector<int>>& board, int x, int y) {
        int cnt = 0;
        for(int i = 0; i < 8; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                if(board[nx][ny] == 1 || board[nx][ny] == 3) cnt++;
            }
        }
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int cnt = countLive(board, i, j);
                if(board[i][j] == 1) {
                    if(cnt < 2 || cnt > 3) {
                        board[i][j] = 3;
                    }
                }
                else if(board[i][j] == 0) {
                    if(cnt == 3) board[i][j] = 2;
                }
            }
        }
        for(auto &x: board) {
            for(auto &y: x) {
                if(y == 3) y = 0;
                else if(y == 2) y = 1;
            }
        }
    }
};