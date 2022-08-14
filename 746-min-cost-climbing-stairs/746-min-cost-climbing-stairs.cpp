class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp1 = cost[0], dp2 = cost[1];
        for(int i = 2; i <= n; i++) {
            int temp = min(dp1,  dp2) + (i == n ? 0 : cost[i]);
            dp1 = dp2;
            dp2 = temp;
        }
        return dp2;
    }
};