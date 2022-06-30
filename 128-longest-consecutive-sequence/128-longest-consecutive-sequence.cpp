class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for(int num: nums) {
            int cnt = 1;
            if(st.find(num - 1) == st.end()) {
                while(st.find(num + 1) != st.end()) {
                    num++;
                    cnt++;
                }
            }
            res = max(res, cnt);
        }
        return res;
    }
};