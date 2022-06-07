class Solution {
public:
    bool isValid(vector<int>& nums, int mid, int m) {
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum > mid) {
                sum = nums[i];
                m--;
            }
        }
        return m > 0;
    }
    int splitArray(vector<int>& nums, int m) {
        int left = 0, right = 0;
        for(int x: nums) {
            left = max(left, x);
            right += x;
        }
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(nums, mid, m)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};