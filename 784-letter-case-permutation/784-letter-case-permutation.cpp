class Solution {
public:
    vector<string> res;
    void solve(string s, int i) {
        if(i == s.size()) {
            res.push_back(s); 
            return;
        }
        
        solve(s, i + 1);
        if(isalpha(s[i])) {
            char c = s[i];
            s[i] = islower(s[i]) ? toupper(s[i]) : tolower(s[i]);
            solve(s, i + 1);
            s[i] = c;
        }
    }
    vector<string> letterCasePermutation(string s) {
        solve(s, 0);
        return res;
    }
};