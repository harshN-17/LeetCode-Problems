// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool checkForCycle(int node, vector<int> &vis, vector<int> &vis2, vector<int> adj[]){
        vis[node] = 1;
        vis2[node] = 1;
        for (auto it: adj[node]) {
            if (!vis[it]) {
                if (checkForCycle(it, vis, vis2, adj))
                    return true;
            }
            else if (vis2[it])
                return true;
        }
        vis2[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector < int > adj[]) {
        vector <int> vis(V, 0);
        vector<int> vis2(V,0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (checkForCycle(i, vis, vis2, adj)) return true;
            }
        }
        return false;
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