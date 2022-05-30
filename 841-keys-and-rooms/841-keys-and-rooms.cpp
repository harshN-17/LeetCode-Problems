class Solution {
public:
    void solve(vector<vector<int>>& rooms, vector<bool>& vis, int node){
        //base-case
        if(vis[node]) return;
        
        //mark visited
        vis[node] = true;
        
        for(auto it: rooms[node]){
            if(!vis[it]) solve(rooms, vis, it);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n,false);
        solve(rooms, vis, 0);
        for(auto it: vis){
            if(!it) return false;
        }
        return true;
    }
};