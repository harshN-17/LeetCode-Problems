class Solution {
public:
    static bool cmp(string s1, string s2) {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> mp;
        sort(words.begin(), words.end(), cmp);
        int res = 0;
        for(string s: words) {
            for(int i = 0; i < s.size(); i++) {
                string temp = s.substr(0,i) + s.substr(i+1);
                mp[s] = max(mp[s], mp.find(temp) == mp.end() ? 1 : mp[temp] + 1) ;
            }
            res = max(res, mp[s]);
        }
        return res;
    }
};