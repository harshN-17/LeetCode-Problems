class Solution {
public:
    vector<int> memo;
    bool solve(string &s, unordered_set<string>& dict, int idx) {
        if(idx == s.size()) return true;
        if(memo[idx] != -1) return memo[idx];
        string temp = "";
        for(int i = idx; i < s.size(); i++) {
            temp += s[i];
            if(dict.find(temp) != dict.end()) {
                if(solve(s, dict, i + 1)) return memo[idx] = true;
            }
        }
        return memo[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        memo.assign(n + 1, -1);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return solve(s, dict, 0);
    }
};