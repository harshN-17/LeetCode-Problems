class Solution {
public:
    #define MOD 1000000007
    
    int numRollsToTarget(int n, int K, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            vector<int> dp2(target + 1);
            for(int j = 1; j <= K; j++) {
                for(int k = j; k <= target; k++) {
                    dp2[k] = (dp2[k] + dp[k - j]) % MOD;
                }
            }
            swap(dp, dp2);
        }
        return dp[target];
    }
};