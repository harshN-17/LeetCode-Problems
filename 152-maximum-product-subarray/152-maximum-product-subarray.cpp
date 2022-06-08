class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxprod = 1, minprod = 1, res = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i] < 0) {
                swap(maxprod, minprod);
            }
            maxprod = max(maxprod * nums[i], nums[i]);
            minprod = min(minprod * nums[i], nums[i]);
            res = max(res, maxprod);
        }
        return res;
    }
};