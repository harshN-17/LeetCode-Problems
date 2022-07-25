class Solution {
public:
    int lastOccur(vector<int>& nums, int target){
        int st=0, en=nums.size()-1, mid,ans=-1;
        while(st<=en){
            mid = st + (en-st)/2;
            if(nums[mid]>target) en=mid-1;
            else if(nums[mid]<target) st=mid+1;
            else{
                ans = mid;
                st=mid+1;
            }
        }
        
        return ans;
    }
    
    int firstOccur(vector<int>& nums, int target){
        int st=0, en=nums.size()-1, mid,ans=-1;
        while(st<=en){
            mid = st + (en-st)/2;
            if(nums[mid]>target) en=mid-1;
            else if(nums[mid]<target) st=mid+1;
            else{
                ans = mid;
                en=mid-1;
            }
        }
        
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(firstOccur(nums,target));
        ans.push_back(lastOccur(nums,target));
        return ans;
    }
};