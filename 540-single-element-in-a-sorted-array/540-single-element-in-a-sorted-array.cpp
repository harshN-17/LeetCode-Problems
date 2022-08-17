class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1, mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(mid == 0 || (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])) {
                return nums[mid];
            }
            if(mid & 1){
                if(nums[mid] == nums[mid - 1]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            else{
                if(nums[mid] == nums[mid - 1]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1; 
                }
            }
        }
        return nums[mid];
    }
};