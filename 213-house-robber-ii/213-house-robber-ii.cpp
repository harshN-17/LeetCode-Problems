class Solution {
public:
    int solve(vector<int>& nums, int left, int right){
        int premax=0, curmax=0;
        for(int i=left; i<right; i++) {
            int t = curmax;
            curmax = max(premax + nums[i], curmax);
            premax = t;
        }
        return curmax;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        return max(solve(nums, 0, n -1) , solve(nums, 1, n));
    }
};