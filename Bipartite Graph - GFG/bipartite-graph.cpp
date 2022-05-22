// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool solve(vector<int> adj[], vector<int> &color, int node){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int k = q.front();
            q.pop();
            for(int x: adj[k]){
                if(color[x]==-1){
                    color[x] = 1-color[k];
                    q.push(x);
                }
                else if(color[x]==color[k]) return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    for(int i=0; i<V; i++){
	        if(color[i]==-1){
	            if(!solve(adj, color, i)) return false;
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends