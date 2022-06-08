class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& cand, vector<int> temp, int index, int sum, int target){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
                
        while(index < cand.size() and sum <= target) {
            temp.push_back(cand[index]);
            solve(cand, temp, index + 1, sum + cand[index], target);
            temp.pop_back();
            index++;
            while(index < cand.size() and cand[index] == cand[index-1]) index++;
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates, temp, 0, 0, target);        
        return ans;    
    }
};