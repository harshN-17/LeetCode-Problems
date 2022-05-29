class Solution {
public:
    vector<pair<int,int>> dir {{1,0},{-1,0},{0,1},{0,-1}};
 
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        int ans = 0;
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty()){
            int size = q.size();
            ans++;
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nx = x+dir[i].first;
                    int ny = y+dir[i].second;
                    if(nx<0 or ny<0 or nx>=n or ny>=m or maze[nx][ny]=='+') continue;
                    if(nx*ny == 0 or nx==n-1 or ny==m-1) return ans;
                    q.push({nx,ny});
                    maze[nx][ny] = '+';
                }
            }
        }
        
        
        
        return -1;
    }
};