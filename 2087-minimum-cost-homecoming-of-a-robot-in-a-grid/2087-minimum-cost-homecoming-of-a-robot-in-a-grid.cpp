class Solution {
public:
    //NO DFS DP BACKTRACK !!!!
    // vector<int> dir = {0 , 1, 0 , -1, 0};
    // int dfs(vector<int>& cur, vector<int>& home, vector<int>& rowCosts, vector<int>& colCosts) {
    //     if(cur[0] < 0 || cur[1] < 0 || cur[0] >= rowCosts.size() || cur[1] >= colCosts.size()) return 0;
    //     if(cur[0] == home[0] && cur[1] == home[1]) return 0;
    //     grid[x][y] = 1;
    //     for(int i = 0; i < 4; i++) {
    //         int nx = x + dir[i];
    //         int ny = y + dir[i + 1];
    //         res = min(dfs());
    //     }
    // }
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int res = 0;
        for(int i = homePos[0]; i != startPos[0]; i += i < startPos[0] ? 1 : -1) {
            res += rowCosts[i];
        }
        for(int i = homePos[1]; i != startPos[1]; i += i < startPos[1] ? 1 : -1) {
            res += colCosts[i];
        }
        return res;
    }
};