class Solution {
public:
    bool check(vector<vector<int>> &graph, vector<int> &color, int node){
        if(color[node]==-1) color[node] = 1;
        
        for(int x: graph[node]){
            if(color[x]==-1){
                color[x] = 1-color[node];
                if(!check(graph, color, x)) return false;
            }
            else if(color[x]==color[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!check(graph, color, i)) return false;
            }
        }
        return true;
    }
};