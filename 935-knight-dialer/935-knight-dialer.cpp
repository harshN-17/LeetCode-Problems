# define MOD 1000000007
class Solution {
public:
    vector<vector<vector<int>>> memo;
    vector<vector<int>> dir = {
        {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    int solve(int n, int i, int j) {
        if(i<0 || j<0 || i>=4 || j>=3 || (i==3 && j!=1)) return 0;
        if(n == 1) {
            return 1;
        }
        if(memo[n][i][j] != -1) return memo[n][i][j];
        int res = 0;
        for(int k = 0; k < 8; k++) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if((x>=0 && y>=0 && x<3 && y<3) || (x==3 && y==1)) {
                res = (res % MOD + solve(n - 1, x, y) % MOD) % MOD;
            }
        }
        return memo[n][i][j] = res;
    }
    int knightDialer(int n) {
        int res = 0;
        memo.resize(n + 1, vector<vector<int>>(4, vector<int>(3, -1)));
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                res = (res % MOD + solve(n, i, j) % MOD) % MOD;
            }
        }
        return res;
    }
};