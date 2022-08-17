class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;
        unordered_set<int> vis;
        for(auto &it: adjacentPairs) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        vector<int> res;
        queue<int> q;
        for(auto it: indegree) {
            if(it.second == 1) {
                q.push(it.first);
                vis.insert(it.first);
                break;
            }
        }
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            for(auto &it: graph[cur]) {
                if(!vis.count(it)) {
                    vis.insert(it);
                    q.push(it);
                }
            }
        }
        return res;
    }
};