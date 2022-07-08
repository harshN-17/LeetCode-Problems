class Solution {
public:
    // unordered_map<string, int> memo;
    int numSquares(int n, int i = 1) {
//         if(n == 0) return 0;
//         int sq = sqrt(n);
//         if(sq * sq == n) return 1;
//         if(i > sqrt(n)) return INT_MAX - 1;
//         string key = to_string(n) + "|" + to_string(i);
//         if(memo.find(key) != memo.end()) return memo[key];
//         int res = numSquares(n, i + 1);
//         if(n - i * i >= 0) {
//             res = min(res, 1 + numSquares(n - i * i, i));
//         }
//         return memo[key] = res;
        int sq = floor(sqrt(n));
        if(sq * sq == n) return 1;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j * j <= i; j++) {
                if(j * j == i) dp[i] = 1;
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        } 
        return dp[n];
    }
};