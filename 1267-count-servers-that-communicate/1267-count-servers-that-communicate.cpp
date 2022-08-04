class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if(parent[x] == -1) {
            parent[x] = x;
        }
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unionSet(int x, int y) {
        int u = find(x), v = find(y);
        if(u != v) {
            parent[u] = v;
        }
    }
    
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        parent.assign(n * m, -1);
        for(int i = 0; i < n; i++) {
            int j = 0;
            while(j < m && grid[i][j] == 0) {
                j++;
                continue;
            }
            for(int k = j + 1; k < m; k++) {
                if(grid[i][k])
                    unionSet(i * m + j, i * m + k);
            }
            
        }
        
        for(int j = 0; j < m; j++) {
            int i = 0;
            while(i < n && grid[i][j] == 0) {
                i++;
                continue;
            }
            for(int k = i + 1; k < n; k++) {
                if(grid[k][j])
                    unionSet(i * m + j, k * m + j);
            }
            
        }
        
        unordered_map<int, int> parentCount;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] && find(i * m + j) != (i * m + j)) parentCount[find(i * m + j)]++;
            }
        }
        int res = 0;
        for(auto it: parentCount) {
            res += it.second + 1;
        }
        return res;
    }
};