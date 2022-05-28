class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size()+1;
        for(int i=0; i<n-1; i++){
            if(nums[i]%n==n-1) continue;
            nums[nums[i]%n] += n;
        }
        for(int i=0; i<n-1; i++){
            if(nums[i]<n) return i;
        }
        return n-1;
    }
};