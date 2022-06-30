class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int med = 0;
        int res = 0;
        if((n & 1) == 0) {
            med = nums[n / 2] + nums[n / 2 - 1];
            med /= 2;
        }
        else {
            med = nums[n / 2];
        }
        for(int x: nums) {
            res += abs(med - x);
        }
        return res;
    }
};