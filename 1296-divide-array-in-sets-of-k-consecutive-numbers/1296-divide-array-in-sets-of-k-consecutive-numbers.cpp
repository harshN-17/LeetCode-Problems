class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto &x: nums) {
            freq[x]++;
        }
        sort(nums.begin(), nums.end());
        for(auto x: nums) {
            if(freq[x] == 0) continue;
            for(int i = 1; i <= k; i++) {
                if(freq[x] == 0) return false;
                freq[x]--;
                x++;
            }
        }
        return true;
    }
};