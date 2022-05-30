class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int node){
        if(vis[node]) return;
        vis[node] = true;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(adj, vis, it);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n,vector<int>());
        vector<bool> vis(n,false);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j])
                    adj[i].push_back(j);
            }
        }
        
        int ans=0;
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(adj, vis, i);
                ans++;
            }
        }
            
        return ans;
    }
};