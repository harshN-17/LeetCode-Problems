class Solution {
public:
    bool check(vector<int>& candies, long long mid, long long k) {
        if(mid == 0) return true;
        long long cnt = 0;
        for(auto &x: candies) {
            cnt += (x/mid);
        } 
        return cnt >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 0, right = 1;
        for(int &x: candies) right += x;
        int ans;
        while(left <= right) {
            long long mid = left + (right - left) / 2;
            if(check(candies, mid, k)) {
                ans = mid   ;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
};