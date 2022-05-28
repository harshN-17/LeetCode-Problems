// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:

    bool isCyclic(int V, vector < int > adj[]) {
        int cnt=0;
        vector<int> indegree(V,0);
        for (int i = 0; i < V; i++) {
            for(int it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;

        for(int i=0; i<V; i++)
            if(!indegree[i]) q.push(i);
            
        while(!q.empty()){
            int t = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[t]){
                if(--indegree[it]==0) q.push(it);
            }
        }
        return !(cnt==V) ;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends