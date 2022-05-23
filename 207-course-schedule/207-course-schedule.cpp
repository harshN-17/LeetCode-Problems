class Solution {
public:
    bool solve(vector<vector<int>> &adj, vector<bool>& vis, vector<bool>& vis2, int node){
        vis[node]=true;
        vis2[node]=true;
        for(int x: adj[node]){
            if(!vis[x]){
                if(solve(adj,vis,vis2,x)) return true;
            }
            if(vis2[x]) return true;
        }
        vis2[node] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n, vector<int>());
        for (auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        // for(int i=0; i<n; i++){
        //     adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        // }
    
        vector<bool> vis(n,false);
        vector<bool> vis2(n,false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(solve(adj, vis, vis2, i)) return false;
            }     
        }
        return true;
    }
};