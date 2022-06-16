class Solution {
public:
    bool isCycle(vector<vector<int>>& graph, vector<int> &res, vector<int> &vis, vector<int> &vis2, int node) {
        
        vis[node] = vis2[node] = true;
        
        for(auto it: graph[node]) {
            if(!vis[it] and isCycle(graph, res, vis, vis2, it)) return true;
            if(vis2[it]) return true;
        }
        
        vis2[node] = false;
        res.push_back(node);
        return false;
    }
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<vector<int>> graph(num, vector<int>());
        vector<int> res;
        vector<int> vis(num, false);     
        vector<int> vis2(num, false);   
        
        for(auto it: pre) {
            graph[it[1]].push_back(it[0]);
        }
        
        for(int i=0; i<num; i++){
            if(!vis[i] and isCycle(graph, res, vis, vis2, i)) return {};                     
        }

        reverse(res.begin(), res.end());
        return res;
    }
};