class Solution {
public:
    unordered_map<string, int> dp;
    int solve(vector<int>& stones, int index, int sum) {
        if(index == stones.size()) return sum;
        string key = to_string(sum) + "|" + to_string(index);
        if(dp.find(key) != dp.end()) return dp[key];
        return dp[key] = min(solve(stones, index + 1, sum + stones[index]), solve(stones, index + 1, abs(sum - stones[index]))) ;
    }
    int lastStoneWeightII(vector<int>& stones) {
        return solve(stones, 0, 0);
    }
};