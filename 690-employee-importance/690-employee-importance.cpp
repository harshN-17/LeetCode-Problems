/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int bfs(unordered_map<int, Employee*> &graph, int id) {
        queue<int> q;
        q.push(id);
        int res = 0;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            res += graph[cur]->importance;
            for(auto it: graph[cur]->subordinates) {
                q.push(it);
            }
        }
        return res;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> graph;
        for(auto it: employees) graph[it->id] = it;
        return bfs(graph, id);
    }
};