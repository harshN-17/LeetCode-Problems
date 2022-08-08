class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1) 
                    dp[i] = dp[j] + 1;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};





    // int lowerBound(vector<int>& temp, int x) {
    //     int left = 0, right = temp.size();
    //     while(left < right) {
    //         int mid = left + (right - left) / 2;
    //         if(temp[mid] < x) left = mid + 1;
    //         else{
    //             right = mid;
    //         }
    //     }
    //     return left;
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     vector<int> temp;
    //     for(int i = 0; i < nums.size(); i++) {
    //         if(temp.size() == 0 || temp.back() < nums[i])
    //             temp.push_back(nums[i]);
    //         else {
    //             int idx = lowerBound(temp, nums[i]);
    //             temp[idx] = nums[i];
    //         }
    //     }
    //     return temp.size();
    // }