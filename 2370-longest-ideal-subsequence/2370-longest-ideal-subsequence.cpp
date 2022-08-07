class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &s, int &k, int index, char last) {
        if(index >= s.size()) return 0;
        if(dp[index][last] != -1) return dp[index][last];
        int pick = 0;
        if(abs(s[index] - last) <= k || last == '#') 
            pick = 1 + solve(s, k, index + 1, s[index]);
        int skip = solve(s, k, index + 1, last);
        return dp[index][last] = max(pick, skip);
    }
    int longestIdealString(string s, int k) {
        int res = 0;
        dp.assign(s.size(), vector<int>(150, -1));
        return solve(s, k, 0, '#');
    }
};