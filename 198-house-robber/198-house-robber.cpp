class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int index) {
        if(index<0) return 0;
        if(dp[index] != -1) return dp[index];
        int include = solve(nums,index-2) + nums[index];
        int exclude = solve(nums, index-1);
        dp[index] = max(include, exclude); 
        return max(include, exclude);
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return solve(nums, nums.size()-1);
    }
};