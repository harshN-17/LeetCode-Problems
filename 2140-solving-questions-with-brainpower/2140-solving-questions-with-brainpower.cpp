class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n);
        dp[n - 1] = questions[n - 1][0];
        for(int i = n - 2; i >= 0; i--) {
            int nextIndex = i + 1 + questions[i][1];
            long long temp = questions[i][0] + (nextIndex < n ? dp[nextIndex] : 0);
            dp[i] = max(dp[i + 1], temp);
        }
        return dp[0];
    }
};
