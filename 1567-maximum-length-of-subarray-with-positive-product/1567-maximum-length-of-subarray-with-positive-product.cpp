class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int i = -1, j = 0, firstneg = -1, neg = 0, res = 0;
        while(j < n) {
            if(nums[j] == 0) {
                i = j;
                neg = 0;
                firstneg = -1;
            }
            if(nums[j] < 0) neg++;
            if(neg == 1 && firstneg == -1) firstneg = j;
            if(neg % 2 == 0) res = max(res, j - i);
            else res = max(res, j - firstneg);
            j++;
        }
        return res;
    }
};