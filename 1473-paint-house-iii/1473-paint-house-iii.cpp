class Solution {
public:
    int memo[101][101][22];
    int solve(vector<int>& houses, vector<vector<int>>& cost, int &m, int &n, int &target, int count, int index, int prev) {
        if(index == m) return count == target ? 0 : 1e7 + 1;
        if(index > m) return 1e7 + 1;
        if(memo[count][index][prev] != -1) return memo[count][index][prev];
        int res = 1e7 + 1;
        if(houses[index] != 0) {
            if(prev != houses[index]) res = solve(houses, cost, m, n, target, count + 1, index + 1, houses[index]);
            else res = solve(houses, cost, m, n, target, count, index + 1, houses[index]);
        }
        else {
            for(int i = 1; i <= n; i++) {
                int tmp;
                if(prev != i)
                    tmp = cost[index][i - 1] + solve(houses, cost, m, n, target, count + 1, index + 1, i);
                else
                    tmp = cost[index][i - 1] + solve(houses, cost, m, n, target, count, index + 1, i);
                res = min(res, tmp);
            }
        }
        return memo[count][index][prev] = res;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(memo, -1, sizeof(memo));
        int res = solve(houses, cost, m, n, target, 0, 0, 0);
        return res == 1e7 + 1 ? -1 : res;
    }
};