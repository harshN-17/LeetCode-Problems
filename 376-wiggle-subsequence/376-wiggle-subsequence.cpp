class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        int res = nums[0] == nums[1] ? 1 : 2;
        int prevdiff = nums[1] - nums[0];
        for(int i = 2; i < n; i++) {
            int diff = nums[i] - nums[i - 1];
            if((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
                res++;
                prevdiff = diff;
            }
        }   
        return res;
    }
};