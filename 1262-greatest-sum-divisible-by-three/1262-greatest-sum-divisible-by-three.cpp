class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, INT_MIN));
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 3; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j + nums[i - 1]) % 3] + nums[i - 1]);
            }
        }
        return dp[n][0];
    }
};


