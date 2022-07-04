class Solution {
public:
    void bfs(vector<vector<int>>& adj, vector<vector<bool>>& isReachable, int i) {
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int node = q.front();
                isReachable[i][node] = true;
                q.pop();
                for(auto it: adj[node]) {
                    if(!isReachable[i][it]) {
                        q.push(it);
                        isReachable[i][it] = true;
                    }
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        int size = pre.size();
        vector<vector<int>> adj(n, vector<int>());
        for(int i = 0; i < size; i++) {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<vector<bool>> isReachable(n, vector<bool>(n,false));
        for(int i = 0; i < n; i++) {
            bfs(adj, isReachable, i);
        }
        int q = queries.size();
        vector<bool> res(q, false);
        for(int i = 0; i < q; i++) {
            res[i] = isReachable[queries[i][0]][queries[i][1]];
        }
        return res;
    }
};