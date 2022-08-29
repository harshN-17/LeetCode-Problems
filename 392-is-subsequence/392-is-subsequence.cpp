class Solution {
public:
    vector<vector<int>> memo;
    bool solve(string &s, string& t, int i, int j) {
        if(s.size() <= i) return true;
        if(t.size() <= j) return false;
        if(s[i] == t[j]) {
            i++;
        }
        if(memo[i][j] != -1) return memo[i][j];
        if(solve(s, t, i, j + 1)) return memo[i][j] = true;
        
        return memo[i][j] = false;
    }
    bool isSubsequence(string s, string t) {
        memo.assign(s.size() + 1, vector<int>(t.size() + 1, -1));
        return solve(s, t, 0, 0);
    }
};