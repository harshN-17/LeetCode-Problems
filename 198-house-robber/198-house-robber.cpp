class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, cur = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int temp = max(prev + nums[i], cur);
            prev = cur;
            cur = temp;
        }
        return cur;
    }
};