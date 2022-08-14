class Solution {
public:
    int solve(vector<int>& nums, int left, int right) {
        int dp1 = 0, dp2 = 0;
        for(int i = left; i <= right; i++) {
            int temp = max(dp1 + nums[i], dp2);
            dp1 = dp2;
            dp2 = temp;
        }
        return dp2;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        return max(solve(nums, 0, nums.size() - 2), solve(nums, 1, nums.size() - 1));
    }
};