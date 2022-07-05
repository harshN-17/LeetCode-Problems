class Solution {
public:
    vector<int> dp;
    int minCost(vector<int>& cost, int index) {
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        return dp[index] = min(minCost(cost, index - 1), minCost(cost, index - 2)) + (index == cost.size() ? 0 : cost[index]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size() + 1, -1);
        return minCost(cost, cost.size());
    }
};