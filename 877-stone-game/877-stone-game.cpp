class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& piles, int i, int j, bool turn) {
        if(i >= j) {
            return  0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(turn) {
            dp[i][j] = max(piles[j] + solve(piles, i, j - 1, false) , piles[i] + solve(piles, i + 1, j, false));
        }
        else {
            dp[i][j] = min(-piles[j] + solve(piles, i, j - 1, true) , -piles[i] + solve(piles, i + 1, j, true));
        }

        return dp[i][j];
    }
    bool stoneGame(vector<int>& piles) {
        dp.assign(piles.size(), vector<int>(piles.size(), -1));
        return solve(piles, 0, piles.size() - 1, true) > 0;
    }
};