class Solution {
public:
    void solve(vector<vector<int>>& rooms, vector<bool>& vis){
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            vis[node]= true;
            q.pop();
            for(auto it: rooms[node]){
                if(!vis[it]) q.push(it);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n,false);
        solve(rooms, vis);
        
        for(auto it: vis){
            if(!it) return false;
        }
        return true;
    }
};