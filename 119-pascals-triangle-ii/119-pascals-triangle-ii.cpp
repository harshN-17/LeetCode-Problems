class Solution {
public:
    vector<int> getRow(int row) {
        vector<int> dp(row + 1);
        for(int i = 0; i <= row; i++) {
            vector<int> temp(i + 1);
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) temp[j] = 1;
                else {
                    temp[j] = dp[j] + dp[j - 1];
                }
            }
            dp = temp;
        }
        return dp;
    }
};