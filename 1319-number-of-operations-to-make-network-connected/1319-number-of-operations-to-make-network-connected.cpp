class Solution {
public:
    void solve(vector<vector<int>>& adj, vector<bool>& vis, int i){
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int it: adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = true;
                }
            }   
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n,vector<int>());
        
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int components = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                components++;
                solve(adj,vis,i);
            }
        }
        return components-1;
    }
};