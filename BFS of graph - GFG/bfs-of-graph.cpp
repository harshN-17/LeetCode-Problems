// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int> bfs;
        vector<bool> vis(v+1,false);
        for(int i=0; i<v; i++){
            if(vis[i]==false){
                vis[i]=true;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int t = q.front();
                    bfs.push_back(t);
                    q.pop();
                    for(auto x:adj[t]){
                        if(vis[x]==false){
                            vis[x] = true;
                            q.push(x);
                        }
                    }
                }
            }
            break;
        }
        return bfs;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends