class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp.insert({'I', 1});
        mp.insert({'V', 5});
        mp.insert({'X', 10});
        mp.insert({'L', 50});
        mp.insert({'C', 100});
        mp.insert({'D', 500});
        mp.insert({'M', 1000});
        int res = 0;
        for(int i = 1; i <= s.size(); i++) {
            if(i == s.size() || mp[s[i]] <= mp[s[i - 1]]) {
                res += mp[s[i - 1]];
            }
            else {
                res += (mp[s[i]] - mp[s[i - 1]]);
                i++;
            }
        }
        return res;
    }
};