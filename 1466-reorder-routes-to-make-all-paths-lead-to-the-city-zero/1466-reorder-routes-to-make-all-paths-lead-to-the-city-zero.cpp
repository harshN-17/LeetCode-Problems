class Solution {
public:
    int solve(vector<vector<int>> &out, vector<vector<int>> &in, vector<bool>& vis){
        queue<int> q;
        q.push(0);
        int ans=0;
        vis[0]=true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: out[node]){
                if(!vis[it]){
                    ans++;
                    vis[it] = true;
                    q.push(it);
                }
            }               
            for(auto it: in[node]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
        return ans;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        vector<bool> vis(n,false);
        vector<vector<int>> out(n,vector<int>());
        vector<vector<int>> in(n,vector<int>());

        for(int i=0; i<m; i++){
            out[connections[i][0]].push_back(connections[i][1]);
            in[connections[i][1]].push_back(connections[i][0]);
        }
        
        int ans=solve(out,in,vis);        
        
        return ans;
    }
};