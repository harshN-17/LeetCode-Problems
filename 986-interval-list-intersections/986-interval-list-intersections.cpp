class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        int n = firstList.size(), m = secondList.size();
        if(n == 0 || m == 0) return {};
        vector<vector<int>> res;
        while(i < n && j < m) {
            int x = max(firstList[i][0], secondList[j][0]);
            int y;
            if(firstList[i][1] < secondList[j][1]) {
                y = firstList[i][1];
                i++;                
            }
            else {
                y = secondList[j][1];
                j++;                
            }
            if(x > y) {
                continue;                    
            }
            res.push_back({x,y});
        }
        
        return res;
    }
};