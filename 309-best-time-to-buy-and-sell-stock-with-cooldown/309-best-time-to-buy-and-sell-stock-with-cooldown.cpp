class Solution {
public:
    vector<vector<int>> memo;
    int solve(vector<int>& prices, int i, bool canBuy) {
        if(prices.size() <= i) return 0;
        if(memo[i][canBuy] != -1) return memo[i][canBuy];
        if(canBuy) {
            int skip = solve(prices, i + 1, true);
            int buy = -prices[i] + solve(prices, i + 1, false);
            return memo[i][canBuy] = max(skip, buy);
        }
        else {
            int skip = solve(prices, i + 1, false);
            int sell = prices[i] + solve(prices, i + 2, true);
            return memo[i][canBuy] = max(skip, sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        memo.assign(prices.size() + 2, vector<int>(2, -1));
        return solve(prices, 0, true);
    }
};