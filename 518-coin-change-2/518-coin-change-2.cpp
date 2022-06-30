class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(2, vector<int>(amount + 1));
        //for every coin and amount 0
        dp[0][0] = dp[1][0] = 1;
        //for every amount and 0 coins        
        for(int i = 1; i <= amount; i++) dp[0][i] = 0;        
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(coins[i - 1] > j) dp[i % 2][j] = dp[(i - 1) % 2][j];
                else dp[i % 2][j] = dp[(i - 1) % 2][j] + dp[i % 2][j - coins[i - 1]];
            }
        }
        
        return dp[n%2][amount];
    }
};