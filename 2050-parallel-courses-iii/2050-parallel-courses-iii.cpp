class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n);
        vector<int> indeg(n, 0);
        vector<int> dist(n);
        for(auto course: relations) {
            graph[course[0] - 1].push_back(course[1] - 1);
            indeg[course[1] - 1]++;
        }
        queue<int> q;
        for(int i = 0; i < n ; i++) {
            if(indeg[i] == 0) q.push(i);
            dist[i] = time[i];
        }
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(auto it: graph[cur]) {
                dist[it] = max(dist[it], dist[cur] + time[it]);
                if(--indeg[it] == 0) q.push(it);
            }
        }
        return *max_element(dist.begin(), dist.end());
    }
};