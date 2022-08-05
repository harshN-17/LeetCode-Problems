class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& in, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indeg;
        unordered_set<string> sup(supplies.begin(), supplies.end());
        int n = rec.size();
        for(int i = 0; i < n; i++) {
            indeg[rec[i]] = 0;
            for(auto s: in[i]) {
                graph[s].push_back(rec[i]);
                indeg[rec[i]]++;
            }
        }
        queue<string> q;
        for(auto s: sup) {
            q.push(s);
        }
        vector<string> res;
        while(!q.empty()) {
            string cur = q.front();
            q.pop();
            for(auto it: graph[cur]) {
                if(--indeg[it] == 0) {
                    q.push(it);
                    res.push_back(it);
                }
            }
        }
        return res;
    }
};