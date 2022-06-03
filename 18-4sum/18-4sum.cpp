class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;  
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k=j+1, l=n-1;
                int diff = target-nums[i]-nums[j];
                while(k<l){
                    if(nums[k]+nums[l]==diff){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++; l--;
                        while(k<n and nums[k]==nums[k-1]) k++;
                        while(l>=0 and nums[l]==nums[l+1]) l--;
                    }
                    else if(nums[k]+nums[l]<diff) k++;
                    else l--;
                }
                while(j<n-1 and nums[j]==nums[j+1]) j++;
            }
            while(i<n-1 and nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};