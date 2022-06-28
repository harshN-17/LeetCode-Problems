class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res, int index, vector<int> temp) {
        if(nums.size() == index) {
            res.push_back(temp);
            return;
        }
        solve(nums, res, index + 1, temp);
        while(index < nums.size() - 1 && nums[index] == nums[index + 1]) {
            temp.push_back(nums[index++]);
        }
        temp.push_back(nums[index]);
        solve(nums, res, index + 1, temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        solve(nums, res, 0, {});
        return res;
    }
};