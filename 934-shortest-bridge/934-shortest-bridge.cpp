class Solution {
public:
    
    //for navigating in 4 directinons
    vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    //to mark one of the island visited
    void updateIsland(vector<vector<int>>& grid, int i, int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = 2;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                //expand in 4 directions
                for(int i=0; i<4; i++){
                    int newx = x + dir[i].first;
                    int newy = y + dir[i].second;
                    //check if the next cell exists and is a land cell annd push in the queue
                    if(newx>=0 and newy>=0 and newx<grid.size() and newy<grid.size() and grid[newx][newy]==1){
                        q.push({newx,newy});
                        //mark cell visited
                        grid[newx][newy]=2;
                    }
                }
            }
        }
    }
    
    int solve(vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        int n = grid.size();
        //push all the land cells in the queue
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        int ans=0;
        //do bfs over the grid
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                //expand in 4 directions
                for(int i=0; i<4; i++){
                    //calculate the new coordinate
                    int newx = x + dir[i].first;
                    int newy = y + dir[i].second;
                    //check if the next cell exist
                    if(newx>=0 and newy>=0 and newx<grid.size() and newy<grid.size()){
                        // if it is a land cell push in the queue
                        if(grid[newx][newy]==0){
                            q.push({newx,newy});
                            //mark cell visited
                            grid[newx][newy]=1;    
                        }
                        //if its marked 2 then we have reached the first island hence return the ans
                        else if(grid[newx][newy]==2) return ans;
                    }
                }
            }
            //increment ans after every round of expansion
            ans++;
        }
        return ans;
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool flag=false;
        
        // to update the first island
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    updateIsland(grid, i, j);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        
        //return the solution
        return solve(grid);
    }
};