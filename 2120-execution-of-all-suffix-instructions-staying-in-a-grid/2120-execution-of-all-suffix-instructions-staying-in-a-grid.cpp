class Solution {
public:
    int solve(int &n, int r, int c, string& s, int index) {
        if(index == s.size()) {
            return 0;     
        }
        int res = 0;
        switch(s[index]) {
            case 'L': c--; break;
            case 'R': c++; break;
            case 'U': r--; break;
            case 'D': r++; break;
        }
        if(r >= 0 && c >= 0 && r < n && c < n)
            res = 1 + solve(n, r, c, s, index + 1);
        return res;
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> res(m);
        for(int i = 0; i < m; i++) res[i] = solve(n, startPos[0], startPos[1], s, i);
        return res;
    }
};