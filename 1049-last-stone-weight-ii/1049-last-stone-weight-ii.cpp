class Solution {
public:
    unordered_map<string, int> dp;
    int solve(vector<int>& stones, int index, int sum1, int sum2) {
        if(index == stones.size()) return abs(sum1 - sum2);
        string key = to_string(sum1) + "|" + to_string(sum2);
        if(dp.find(key) != dp.end()) return dp[key];
        return dp[key] = min(solve(stones, index + 1, sum1 + stones[index], sum2), solve(stones, index + 1, sum1, sum2 + stones[index])) ;
    }
    int lastStoneWeightII(vector<int>& stones) {
        return solve(stones, 0, 0, 0);
    }
};