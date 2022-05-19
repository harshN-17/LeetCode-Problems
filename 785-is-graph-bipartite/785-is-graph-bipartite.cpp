class Solution {
public:
    bool check(vector<vector<int>> &graph, vector<int> &color, int node){
        queue<int> q;
        q.push(node);
        color[node] = 1;       
        while(!q.empty()){
            int t= q.front();
            q.pop();
            for(int x:graph[t]){
                if(color[x] == -1){
                    color[x] = 1-color[t];
                    q.push(x);
                }
                else if(color[x] == color[t]) return false;
            }
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