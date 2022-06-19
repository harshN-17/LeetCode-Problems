class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cutdp(n);
        vector<vector<bool>> paldp(n, vector<bool>(n, false));

        for(int i = n - 1; i >= 0; i--) {
            cutdp[i] = n - i - 1;
            for(int j = i; j < n; j++) {
                if(s[i] == s[j] && (j - i < 2 || paldp[i+1][j-1])) {
                    paldp[i][j] = true;
                    if(j == n - 1) cutdp[i] = 0;
                    else cutdp[i] = min(cutdp[i], cutdp[j+1] + 1);
                }
            }
        }
        return cutdp[0];    
    }
};