// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    vector<pair<int,int>> dir = {   {-1,2}, {-1,-2}, {1,2}, {1,-2},
                                    {-2,1}, {-2,-1}, {2,1}, {2,-1}   };

    int solve(int sr, int sc, int dr, int dc, int N){
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int ans=0;
        vector<vector<int>> vis(N, vector<int>(N,0));
        vis[sr][sc]=1;
        while(!q.empty()){
            int size = q.size();
            ans++;
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0; i<8; i++){
                    int nx= x+dir[i].first;
                    int ny = y+dir[i].second;
                    if(nx==dr and ny==dc) return ans;
                    if(!(nx<0 or ny<0 or nx>=N or ny>=N) and !vis[nx][ny]){
                        q.push({nx, ny});
                        vis[nx][ny]=1;
                    }
                }
            }
        }
        return -1;
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int sr = KnightPos[0], sc = KnightPos[1];
	    int dr = TargetPos[0], dc = TargetPos[1];
	    if(sc==dc and sr==dr) return 0;
	    return solve(sr-1, sc-1, dr-1, dc-1, N);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends