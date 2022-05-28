class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        
        //pushing all the land cells
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    q.push({i,j});
                }
            }
        }
        
        if(q.size()==n*n) return -1;
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int dist=0;
        while(!q.empty()){
            int size = q.size();
            dist++;
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int newx = x + dir[i].first;
                    int newy = y + dir[i].second;
                    if(newx>=0 and newx<n and newy>=0 and newy<n and !grid[newx][newy]){
                        grid[newx][newy] = 1;
                        q.push({newx,newy});    
                    }
                }
            }
        }
        return dist-1;
    }
};