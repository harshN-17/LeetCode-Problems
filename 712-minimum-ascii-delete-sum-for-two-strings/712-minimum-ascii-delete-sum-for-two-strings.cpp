class Solution {
public:
    // int solve(string s1, string s2, int i, int j) {
    //     if(i >= n || j >= m) {
    //         int res = 0;
    //         while(j < m ) {
    //             res += (int)s2[j++];
    //         }
    //         while(i < n) {
    //             res += (int)s1[i++];
    //         }
    //         return res;
    //     }
    //     if(memo[i][j] != -1) return memo[i][j];
    //     if(s1[i] == s2[j]) return memo[i][j] = solve(s1, s2, i + 1, j + 1);
    //     int del1 = int(s1[i]) + solve(s1, s2, i + 1, j) ;
    //     int del2 = int(s2[j]) + solve(s1, s2, i, j + 1) ;
    //     return memo[i][j] = min(del1, del2);
    // }
    
    
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        //base case when no element of s2
        for(int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + (int)s1[i - 1];
        }
        //base case for no element in s1
        for(int i = 1; i <= m; i++) {
            dp[0][i] = dp[0][i - 1] + (int)s2[i - 1];
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                   dp[i][j] = dp[i - 1][j - 1];
                   continue;
                }
                dp[i][j] = min((int)s1[i - 1] + dp[i - 1][j], (int)s2[j -1] + dp[i][j - 1]);
            }
        } 
        return dp[n][m];        
    }
};