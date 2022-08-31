class Solution {
public:
    // int solve(string &w1, string& w2, int i, int j){
    //     if(0 == i) return j;
    //     if(0 == j) return i;
    //     if(w1[i - 1] == w2[j - 1]) return solve(w1, w2, i - 1, j - 1);
    //     return 1 + min(
    //         {
    //             solve(w1, w2, i - 1, j),
    //             solve(w1, w2, i, j - 1),
    //             solve(w1, w2, i - 1, j - 1)
    //         }
    //     );
    // }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for(int i = 0; i <= n1; i++) dp[i][0] = i;
        for(int i = 0; i <= n2; i++) dp[0][i] = i;
        
        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = 1 + min({
                        dp[i][j - 1],
                        dp[i - 1][j],
                        dp[i - 1][j - 1]
                    });
                }
            }
        }
        return dp[n1][n2];
    }
};