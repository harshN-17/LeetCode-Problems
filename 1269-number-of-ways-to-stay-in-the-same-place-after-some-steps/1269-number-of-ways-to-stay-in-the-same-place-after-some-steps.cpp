# define MOD 1000000007
class Solution {
public:
    // vector<vector<int>> dp;
    unordered_map<string, int> dp;
    int solve(int steps, int arrLen, int index = 0) {
        if(index < 0 || index >= arrLen) return 0;
        if(steps == 0) {
            if(index == 0) return 1;
            return 0;
        }
        
        string key = to_string(steps) + "|" + to_string(index);
        
        if(dp.find(key) != dp.end()) return dp[key];
        
        int stay = solve(steps - 1, arrLen, index) % MOD;
        int left = solve(steps - 1, arrLen, index - 1) % MOD;
        int right = solve(steps - 1, arrLen, index + 1) % MOD;
        
        return dp[key] = ((stay + left) % MOD + right) % MOD;
    }
    int numWays(int steps, int arrLen) {
        // dp.resize(steps + 1, vector<int>(arrLen, -1));
        return solve(steps, arrLen, 0);
    }
};