class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        while(left < right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for(auto num: nums) cnt += (num-1)/mid;
            if(cnt <= maxOperations) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};