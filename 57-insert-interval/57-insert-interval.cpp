class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newIntervals) {
        int i = 0, n = intervals.size();
        vector<vector<int>> res;
        while(i < n && intervals[i][1] <newIntervals[0]) {
            res.push_back(intervals[i++]);
        }
        while(i < n && intervals[i][0] <= newIntervals[1]) {
            newIntervals[0] = min(intervals[i][0], newIntervals[0]);
            newIntervals[1] = max(intervals[i][1], newIntervals[1]);            
            i++;
        }
        
        res.push_back(newIntervals);
        
        while(i < n) {
            res.push_back(intervals[i++]);
        }
        return res;
    }
};