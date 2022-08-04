class Solution {
public:
    unordered_map<int, int> mp;
    int components;
    int find(int x) {
        if(mp.find(x) == mp.end()) {
            components++;   
            mp[x] = x;
        }
        if(mp[x] != x) mp[x] = find(mp[x]);
        return mp[x];
    }
    void unionSet(int x, int y) {
        int u = find(x), v = find(y);
        if(u != v) {
            mp[u] = v;
            components--;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        components = 0;
        for(auto stone: stones) {
            unionSet(stone[0], stone[1] + 10001);
        }
        return n - components;
    }
};