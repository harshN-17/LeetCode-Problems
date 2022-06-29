class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& prices, int index, int k) {
        if(index == prices.size() || !k) return 0;
        
        if(dp[index][k] != -1) return dp[index][k];
        
        //No transaction 
        int ans1 = solve(prices, index + 1, k);
        int ans2;
        if(k%2 != 0) {
            //selling day
            ans2 = prices[index] +  solve(prices, index + 1, k - 1);
        }
        else {
            //buying day
            ans2 = solve(prices, index + 1, k - 1) - prices[index];
        }
        return dp[index][k] = max(ans1, ans2);
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(), vector<int>(5,-1));
        return solve(prices, 0, 4);
    }
};