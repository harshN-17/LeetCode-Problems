class Solution {
public:
    bool isPalin(string s) {
        int l = 0, r = s.size()-1;
        while(l < r) {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    
    void solve(string s, vector<string> t, vector<vector<string>>& res) {
        if(s.size() == 0) {
            res.push_back(t);
            return;
        }
        
        for(int i = 1; i <= s.size(); i++) {
            string left = s.substr(0, i);
            if(isPalin(left)) {
                t.push_back(left);
                solve(s.substr(i), t, res);
                t.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> t;
        solve(s, t, res);
        return res;
    }
};