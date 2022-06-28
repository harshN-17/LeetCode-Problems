class Solution {
public:
    void solve(int &n, int &k, vector<int> temp, vector<vector<int>>& res, int index) {
        if(temp.size() == k) {
            res.push_back(temp);
            return;
        }
        for(int i = index; i <= n; i++) {
            temp.push_back(i);
            solve(n, k, temp, res, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        solve(n, k, {}, res, 1);
        return res;
    }
};