class Solution {
public:
    int dfs(int cur, vector<int>& manager, vector<int>& informTime){
        if(manager[cur] != -1){
            informTime[cur] += dfs(manager[cur], manager, informTime);
            manager[cur] = -1;
        }
        return informTime[cur];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res=0;
        for(int i = 0; i < n; i++) {
            res = max(res, dfs(i, manager, informTime));
        }
        return res;
    }
};