class Solution {
public:
    // int solve(vector<int>& prices, int fee, int i, bool canBuy) {
    //     if(prices.size() <= i) {
    //         return 0;
    //     }
    //     int skip = solve(prices, fee, i + 1, canBuy);
    //     if(canBuy) {
    //         int buy = - prices[i] - fee + solve(prices, fee, i + 1, false);
    //         return max(buy, skip);
    //     }
    //     else {
    //         int sell = prices[i] + solve(prices, fee, i + 1, true);
    //         return max(sell, skip);
    //     }
    // }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> buy(n), sell(n);
        buy[0] = -prices[0] - fee;
        for(int i = 1; i < n; i++) {
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i] - fee);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        return sell[n - 1];
    }
};