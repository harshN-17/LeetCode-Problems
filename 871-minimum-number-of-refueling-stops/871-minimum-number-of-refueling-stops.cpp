class Solution {
public:
//     unordered_map<string, int> memo;
//     int solve(vector<vector<int>>& stations, int target, int pos, int fuel, int i) {
//         if(target <= pos + fuel) return 0;
//         if(i == stations.size() || stations[i][0] - pos > fuel) return 510;
        
//         string s = to_string(pos) + "|" + to_string(fuel);
//         if(memo.find(s) != memo.end()) return memo[s];
        
//         int newpos = stations[i][0] - pos;
//         int newfuel = fuel + stations[i][1] - newpos;
//         int fill = 1 + solve(stations, target, stations[i][0], newfuel , i + 1);
//         int skip = solve(stations, target, pos, fuel, i + 1);
//         return memo[s] = min(fill, skip);
//     }
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // int res = solve(stations, target, 0, startFuel, 0);
        // return res == 510 ? -1 : res;
        int n = stations.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
        for(int i = 0; i <= n; i++) {
            dp[i][0] = startFuel;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i][j] = dp[i - 1][j];
                if(dp[i - 1][j- 1] >= stations[i - 1][0]) {
                    dp[i][j] = max(dp[i][j] , dp[i - 1][j - 1] + stations[i - 1][1]);
                }
            }
        }
        
        for(int i = 0; i <= n; i++) {
            if(dp[n][i] >= target) return i;
        }
        return -1;
    }
};