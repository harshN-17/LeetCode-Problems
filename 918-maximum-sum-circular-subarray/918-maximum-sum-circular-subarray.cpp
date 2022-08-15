class Solution {
public:
    int kadane(vector<int>& nums, int sign) {
        int n = nums.size();
        int cursum = sign * nums[0], maxsum = sign * nums[0], sum = nums[0];
        for(int i = 1; i < n; i++) {
            sum += nums[i];
            if(cursum < 0) cursum = 0;
            cursum += sign * nums[i];
            maxsum = max(maxsum, cursum);
        }
        return sign == 1 ? maxsum : sum + maxsum == 0 ? INT_MIN : sum + maxsum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        
        return max(kadane(nums, 1), kadane(nums, -1));
    }
};