class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size(), cnt=0;
        for(int i=0; i<n; i++){
            
            if(mp[k-nums[i]]>0){
                mp[k-nums[i]]--;
                cnt++;
            }
            else mp[nums[i]]++ ;
        }
        
        return cnt;
    }
};