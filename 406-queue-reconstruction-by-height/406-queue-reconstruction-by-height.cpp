class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return b[0] < a[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);    
        int n = people.size();
        vector<vector<int>> res;
        
        for(int i = 0; i < n; i++) {
            res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};