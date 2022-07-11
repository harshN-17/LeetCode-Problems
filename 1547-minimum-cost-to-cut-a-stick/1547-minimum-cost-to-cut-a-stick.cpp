class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& cuts, int i, int j) {
        if(j <= i + 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = INT_MAX;
        for(int k = i + 1; k < j; k++) {
            res = min(res, cuts[j] - cuts[i] + solve(cuts, i, k) + solve(cuts, k, j));
        }
        return dp[i][j] = res;
    }
    int minCost(int n, vector<int>& cuts) {
        dp.resize(102, vector<int>(102, -1));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return solve(cuts, 0, cuts.size() - 1);
    }
};