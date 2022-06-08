class Solution {
public:
    int lowerBound(vector<int>& temp, int x) {
        int left = 0, right = temp.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(temp[mid] < x) left = mid + 1;
            else{
                right = mid;
            }
        }
        return left;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++) {
            if(temp.size() == 0 || temp.back() < nums[i])
                temp.push_back(nums[i]);
            else {
                int idx = lowerBound(temp, nums[i]);
                temp[idx] = nums[i];
            }
        }
        return temp.size();
    }
};