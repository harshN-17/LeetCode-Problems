class Solution {
public:
    void solve(vector<vector<int>>& graph, vector<bool> &vis, vector<vector<int>>& res, vector<int> temp, int node){
        if(node == graph.size()-1){
            res.push_back(temp);
            return;
        }
        vis[node] = true;
        for(int x: graph[node]){
            if(!vis[x]){
                temp.push_back(x);
                solve(graph, vis, res, temp, x);
                temp.pop_back();
            }
        }
        vis[node] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> vis(v,false);
        temp.push_back(0);
        solve(graph, vis, res, temp, 0);
        return res;
    }
};