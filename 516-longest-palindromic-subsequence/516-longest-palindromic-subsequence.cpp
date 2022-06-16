class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        vector<int> prevdp(n, 0);      
        
        for(int i = n-1; i >= 0; i--) {
            dp[i] = 1;
            for(int j = i+1; j < n; j++) {
                dp[j] = s[i] == s[j] ? 2 + prevdp[j-1] : max(dp[j-1], prevdp[j]);
            }
            prevdp = dp;
        }
        return prevdp[n-1];
    }
};