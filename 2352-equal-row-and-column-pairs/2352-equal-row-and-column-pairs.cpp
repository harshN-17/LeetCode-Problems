class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) {
            string s;
            for(int j = 0; j < n; j++) {
                s += to_string(grid[i][j]);
                s += "#";
            }
            mp[s]++;
        }
        
        for(int i = 0; i < n; i++) {
            string t;
            for(int j = 0; j < n; j++) {
                t += to_string(grid[j][i]);
                t += "#";
            }
            if(mp.find(t) != mp.end()) res += mp[t];
        }       
        return res;
    }
};