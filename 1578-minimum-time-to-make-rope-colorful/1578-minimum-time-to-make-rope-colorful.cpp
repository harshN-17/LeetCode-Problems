class Solution {
public:
    int minCost(string colors, vector<int>& cost) {
        int res = 0;
        int n = colors.size();
        for(int i = 1; i < n; i++) {
            if(colors[i] == colors[i - 1]) {
                res += min(cost[i], cost[i - 1]);
                cost[i] = max(cost[i], cost[i - 1]);
            }
        }
        return res;
    }
};





// vector<vector<int>> memo;
//     int solve(string& colors, vector<int>& neededTime, int cur, int prev) {
//         if(cur >= colors.size()) return 0;
//         if(memo[cur][prev] != -1) return memo[cur][prev];
//         if(prev != colors.size() + 1 && colors[prev] == colors[cur]) {
//             int a = neededTime[prev] + solve(colors, neededTime, cur + 1, cur);
//             int b = neededTime[cur] + solve(colors, neededTime, cur + 1, prev);
//             return memo[cur][prev] = min(a, b);
//         }
//         else return memo[cur][prev] = solve(colors, neededTime, cur + 1, cur);
//     }
//     int minCost(string colors, vector<int>& neededTime) {
//         int n = colors.size();
//         memo.assign(n, vector<int>(n + 2, -1));
//         return solve(colors, neededTime, 0, n + 1);
//     }