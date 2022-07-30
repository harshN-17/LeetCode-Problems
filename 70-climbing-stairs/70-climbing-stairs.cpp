class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1 || n == 2) return n;
        int dp1 = 1, dp2 = 2;
        for(int i = 3; i <= n; i++) {
            int dp = dp1 + dp2;
            dp1 = dp2;
            dp2 = dp;
        }
        return dp2;
    }
};