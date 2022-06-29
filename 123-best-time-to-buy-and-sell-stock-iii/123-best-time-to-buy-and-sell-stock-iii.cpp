class Solution {
public:

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(5,-1));
        
        for(int i = prices.size(); i >= 0; i--) {
            for(int j = 0; j < 5; j++) {
                if(i == prices.size() || j == 0) dp[i][j] = 0;
                else{
                    int ans1, ans2 = 0;
                    ans1 = dp[i+1][j];
                    if(j % 2 == 0) ans2 = dp[i + 1][j - 1] - prices[i];
                    else ans2 = dp[i + 1][j - 1] + prices[i];
                    dp[i][j] = max(ans1, ans2);
                }
            }
        }
        
        return dp[0][4];
    }
};