class Solution {
public:
    double solve(unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string>& vis, string cur, string& dest) {
        if(cur == dest && adj.find(cur) != adj.end()) return 1;
        vis.insert(cur);
        for(auto it: adj[cur]) {
            if(vis.count(it.first)) continue;
            double res = solve(adj, vis, it.first, dest);
            if(res != -1)
                return res * it.second;
        }
        vis.erase(cur);
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        unordered_set<string> vis;
        vector<double> res;
        int n = equations.size();
        for(int i = 0; i < n; i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        for(auto it: queries) {
            string src = it[0], dest = it[1];
            vis.clear();
            res.push_back(solve(adj, vis, src, dest));
        }
        return res;
    }
};