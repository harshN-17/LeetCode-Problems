class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> temp, int sum, int i){
        if(sum == target){
            res.push_back(temp);
            return;
        }
        while(i<candidates.size() and sum<=target){
            temp.push_back(candidates[i]);
            solve(candidates, target, res, temp, sum + candidates[i], i);
            temp.pop_back();
            i++;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        solve(candidates, target, res, temp, 0, 0);
        return res;
    }
};