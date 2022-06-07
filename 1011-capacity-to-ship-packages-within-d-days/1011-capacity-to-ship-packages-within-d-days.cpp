class Solution {
public:
    bool isValid(vector<int>& weights, int days, int mid) {
        int sum = 0, brk = 1;
        for(int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if(sum > mid) {
                sum = weights[i];
                brk++ ;
            }
        }
        return brk <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for(int weight: weights){
            right += weight;
            left = max(left, weight);
        }
        left = max(left, right/days);
        int res;
        while(left < right) {
            int mid = left + (right - left)/2;
            if(isValid(weights, days, mid)) {
                right = mid ;
            }
            else left = mid + 1;
        }
        return left;
    }
};