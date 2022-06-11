class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> pre(n), post(n);
        pre[0] = nums[0];
        int target = -x;
        for(auto it: nums) target += it;
        if(target == 0) return n;
        int sum = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        int res = INT_MIN;
        for(int i = 0; i < n ; i++) {
            sum += nums[i];
            if(mp.find(sum - target) != mp.end())
                res = max(res,i - mp[sum - target]);
            mp[sum] = i;
        }
        return res == INT_MIN ? -1 : n - res;
    }
};