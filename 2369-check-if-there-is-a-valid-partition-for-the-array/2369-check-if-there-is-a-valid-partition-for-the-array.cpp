class Solution {
public:
    bool validPartition(vector<int>& nums, int index = 0) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for(int i = n - 1; i >= 0; i--) {
            if(i + 1 < n && nums[i] == nums[i + 1]) {
                dp[i] |= dp[i + 2];
                if(i + 2 < n && nums[i] == nums[i + 2]) {
                    dp[i] |= dp[i + 3];
                }
            }
            if(i + 2 < n && nums[i] == nums[i + 1] - 1 && nums[i] == nums[i + 2] - 2) {
                dp[i] |= dp[i + 3];
            }
            
        }
        return dp[0];
    }
};