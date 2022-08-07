# define pdi pair<double, int> 
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pdi>> graph(n);
        for(int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({succProb[i], edges[i][1]});
            graph[edges[i][1]].push_back({succProb[i], edges[i][0]});            
        }
        vector<double> prob(n, 0.0);
        vector<int> vis(n , 0);
        priority_queue<pdi> pq;
        pq.push({1.0, start});
        prob[start] = 1.0;
        while(!pq.empty()) {
            double curProb = pq.top().first;
            int curNode = pq.top().second;
            pq.pop();
            if(!vis[curNode]){
                vis[curNode] = 1;
                for(auto childNode: graph[curNode]) {
                    if(prob[childNode.second] < curProb * childNode.first) {
                        prob[childNode.second] = curProb * childNode.first;
                        pq.push({prob[childNode.second], childNode.second}) ; 
                    }
                }
            }
        }
        return prob[end];
    }
};