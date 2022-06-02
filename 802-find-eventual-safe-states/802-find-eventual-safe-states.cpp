class Solution {
public:
    bool solve(vector<vector<int>>& graph, unordered_set<int>& cycle, unordered_set<int>& vis, unordered_set<int>& safe, int node){
        if(safe.find(node) != safe.end()) return true;
        if(cycle.find(node) != cycle.end()) return false;
        if(vis.find(node) != vis.end()){
            cycle.insert(node);
            return false; 
        }
        vis.insert(node);
        for(auto it: graph[node]){
            if(!solve(graph, cycle, vis, safe, it)){
                cycle.insert(node);
                return false;
            }
        }
        safe.insert(node);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_set<int> cycle, safe, vis;
        vector<int> res;
        for(int i=0; i<graph.size(); i++){
            if(solve(graph, cycle, vis, safe, i)) res.push_back(i);
        }
        return res;
    }
};