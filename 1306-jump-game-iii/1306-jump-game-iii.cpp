class Solution {
public:
    bool solve(vector<vector<int>>& graph, vector<bool>& vis, int s, vector<int>& arr){
        if(arr[s]==0) return true;
        vis[s] = true;
        for(auto it: graph[s]){
            if(!vis[it]){
                if(solve(graph, vis, it, arr)) return true;
            }
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<vector<int>>graph(n, vector<int>());
        vector<bool> vis(n,false);
        for(int i=0; i<n; i++){
            if(i+arr[i]<n) graph[i].push_back(i+arr[i]);
            if(i-arr[i]>=0) graph[i].push_back(i-arr[i]);
        }
        return solve(graph,vis,start, arr);
    }
};