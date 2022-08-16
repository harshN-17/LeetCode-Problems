class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msum=nums[0],sum=0;
        for(int &x: nums){
            sum += x;
            msum = max(msum,sum);
            if(sum<0){
                sum=0;
            }
        }
        return msum;
    }
};