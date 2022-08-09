# define pii pair<int, int>
class Solution {
public:
    vector<int> parent, rank;
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void connect(int u, int v) {
        int x = find(u), y = find(v);
        if(x == y) return;
        if(rank[x] > rank[y]) {
            parent[y] = x;
            rank[x] += rank[y];
        }
        else {
            parent[y] = x;
            rank[y] += rank[x];
        }
    }
    
    void reset(int x) {
        parent[x] = x;
    }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int fp) {
        parent.resize(n);
        rank.assign(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
        map<int, vector<pair<int, int>>> mp;
        for(auto m: meetings) {
            mp[m[2]].push_back({m[0], m[1]});
        }   
        connect(0, fp);
        vector<int> curSecret;
        for(auto [t, meets]: mp) {
            curSecret.clear();
            for(auto &it: meets) {
                connect(it.first, it.second);
                curSecret.push_back(it.first);
                curSecret.push_back(it.second);
            }
            
            for(auto &x: curSecret) {
                if(find(x) != find(0)) reset(x);
            }
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(find(i) == find(0)) res.push_back(i);
        }
        return res;
    }
};