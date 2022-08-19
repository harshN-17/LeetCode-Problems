class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, need;
        for(auto &x: nums) freq[x]++;
        for(auto &x: nums) {
            if(freq[x] == 0) continue;
            else if(need[x] > 0) {
                freq[x]--;
                need[x]--;
                need[x+1]++;
            }
            else if(freq[x] > 0 && freq[x + 1] > 0 && freq[x + 2]) {
                freq[x]--;
                freq[x + 1]--;
                freq[x + 2]--;
                need[x + 3]++;
            }
            else return false;
        }
        return true;
    }
};