class Solution {
public:
    int find(vector<vector<int>>& intervals, int target) {
        int left = 0, right = intervals.size() - 1;
        if(intervals[right][0] < target) return -1;
        int ans;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(intervals[mid][0] < target) {
                left = mid + 1;
            }
            else {
                ans = mid;
                right = mid - 1;
            }
        }
        return intervals[ans][2];
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int i = 0;
        for(auto &it: intervals) {
            it.push_back(i++);
        }
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            int target = intervals[i][1];
            int index = find(intervals, target);
            res[intervals[i][2]] = index;
        }
        return res;
    }
};