class Solution {
public:
    int dp[1001][2002];
    int solve(vector<vector<int>>& pairs, int index, int prev = -1001) {
        if(index == pairs.size()) return 0;
        
        if(dp[index][1001+prev] != -1) return dp[index][1001+prev];
        
        if(pairs[index][0] <= prev) return dp[index][1001+prev] = solve(pairs, index + 1, prev);
        
        int include = 1 + solve(pairs, index + 1, pairs[index][1]);
        int exclude = solve(pairs, index + 1, prev);
        
        return dp[index][prev + 1001] = max(include, exclude);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp, -1, sizeof(dp));
        sort(pairs.begin(), pairs.end());
        return solve(pairs, 0);
    }
};