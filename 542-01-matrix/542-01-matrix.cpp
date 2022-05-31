class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));

        //bfs
        vector<pair<int,int>> dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
                
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int newx = x + dir[i].first;
                int newy = y + dir[i].second;
                if(newx>=0 and newy>=0 and newx<n and newy<m){
                    if(dist[newx][newy] > dist[x][y]+1){
                        dist[newx][newy] = dist[x][y]+1;
                        q.push({newx,newy});
                    }
                }
            }
        }
        return dist;
    }
};